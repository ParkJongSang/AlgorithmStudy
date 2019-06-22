#include <cstdio>

const int INF = 9999, SWITCHES = 10, CLOCKS = 16;

const char linked[SWITCHES][CLOCKS+1] = {
    "xxx.............",
    "...x...x.x.x....",
    "....x.....x...xx",
    "x...xxxx........",
    "......xxx.x.x...",
    "x.x...........xx",
    "...x..........xx",
    "....xx.x......xx",
    ".xxxxx..........",
    "...xxx...x...x..",
};

int min(int a, int b){
    return a < b ? a : b;
}

bool areAligned(int *clocks){
    for(int i = 0; i < CLOCKS; i++){
        if(clocks[i] != 12){
            return false;
        }
    }
    return true;
}

void push(int *clocks, int swtch){
    for(int i = 0; i < CLOCKS; i++){
        if(linked[swtch][i] == 'x'){
            clocks[i] += 3;
            if(clocks[i] == 15) clocks[i] = 3;
        }
    }
}

int solve(int *clocks, int swtch){
    if(swtch == SWITCHES) return areAligned(clocks) ? 0 : INF;
    int ret = INF;
    for(int i = 0; i < 4; i++){
        ret = min(ret, i + solve(clocks, swtch + 1));
        push(clocks, swtch);
    }

    return ret;
}

int main(void){
    int c; scanf("%d", &c);
    int arr[16];
    while(c--){
        for(int i = 0; i < 16; i++){
            scanf("%d", &arr[i]);
        }
        printf("%d\n", solve(arr, 0));
    }

    return 0;
}