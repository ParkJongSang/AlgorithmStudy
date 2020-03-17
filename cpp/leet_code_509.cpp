class Solution {
public:
    int fib(int N) {
        long long dp[31];
        dp[0] = 0;
        dp[1] = 1;
        
        for(int i = 2; i < 31; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[N];
    }
};
