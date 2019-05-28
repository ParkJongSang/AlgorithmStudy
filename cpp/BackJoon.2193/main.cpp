#include <stdio.h>

long long dp[91];
int N;

int main(void){
    dp[1] = 1;
    dp[2] = 1;

    for(int i = 3; i < 91; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    scanf("%d", &N);
    printf("%lld\n", dp[N]);
    
    return 0;
}