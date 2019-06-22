#include <cstdio>

#define MAX_L 10000

int cups[MAX_L+1];
int dp[MAX_L+1];
int N;

int max(int a, int b){
    return a > b ? a : b;
}

int main(void){
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        scanf("%d", &cups[i]);
    }
    dp[1] = cups[1];
    dp[2] = cups[1] + cups[2];
    for(int i = 3; i <= N; i++){
        dp[i] = max(dp[i-1], max(dp[i-2] + cups[i], dp[i-3] + cups[i-1] + cups[i]));
    }
    printf("%d\n", dp[N]);
    return 0;
}