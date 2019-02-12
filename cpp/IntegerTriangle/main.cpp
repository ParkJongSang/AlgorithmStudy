#include <iostream>

using namespace std;

int tri[501][501];
int dp[501][501];
int N;

int solve(int n){
    dp[1][1] = tri[1][1];
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i; j++){
            dp[i][j] = max(dp[i-1][j] + tri[i][j], dp[i-1][j-1] + tri[i][j]);
        }
    }
    int ret = 0;
    for(int i = 1; i <= N; i++){
        ret = max(ret, dp[n][i]);
    }
    return ret;
}

int main() {
    cin >> N;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= i; j++){
            cin >> tri[i][j];
        }
    }

    cout << solve(N);

    return 0;
}