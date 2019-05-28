#include <stdio.h>

long long dp[12];
int N;

int main(void){
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for(int i = 4; i < 12; i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    scanf("%d", &N);
    while(N--){
        int input;
        scanf("%d", &input);
        printf("%lld\n", dp[input]);
    }
    
    return 0;
}