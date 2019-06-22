#include <cstdio>

int N;
int ans = 0;
int col[15];

int abs(int a){
    if(a < 0) return -1 * a;
    return a;
}

bool is_possible(int c){
    for(int i = 1; i < c; i++){
        if(col[i] == col[c]) return false;
        if(abs(col[i] - col[c]) == abs(i - c)) return false;
    }
    return true;
}

void queen(int depth){
    if(depth == N) {
        ans++;
        return;
    }
    for(int i = 1; i <= N; i++){
       col[depth+1] = i;
       if(is_possible(depth+1)){
           queen(depth+1);
       }else{
           col[depth+1] = 0;
       }
    }
    col[depth] = 0;
}

int main(void){
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        col[1] = i;
        queen(1);
    }
    printf("%d\n", ans);
    return 0;
}