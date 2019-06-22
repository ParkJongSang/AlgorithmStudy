#include <cstdio>

int N, M;

int min(int a, int b){
    return a < b ? a : b;
}

int main(void){
    scanf("%d %d", &M, &N);
    int ans_min = 1000001;
    int sum = 0;
    for(int i = 1; i <= 100; i++){
        int tmp = i*i;
        if(tmp >= M && tmp <= N){
            sum += tmp;
            ans_min = min(ans_min, tmp);
        }
    }
    if(ans_min == 1000001){
        printf("-1\n");
    }else{
        printf("%d\n%d\n", sum, ans_min);
    }
    return 0;
}