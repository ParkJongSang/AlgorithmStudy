#include <iostream>

using namespace std;

int N, K;
int dp[1001][1001];
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> K;

    for (int i = 1; i < 1001; i++) {
        dp[i][0] = 1;
        dp[i][1] = i;
        dp[i][i] = 1;
    }

    for(int i = 3; i < 1001; i++){
        for(int j = 2; j < i; j++){
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % 10007;
        }
    }

    cout << dp[N][K];

    return 0;
}