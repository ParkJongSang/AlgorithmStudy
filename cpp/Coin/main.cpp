#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int coins[101];
int dp[10001];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> K;

    for(int i = 1; i <= N; i++){
        cin >> coins[i];
    }
    dp[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = coins[i]; j <= K; j++)
        {
            dp[j] += dp[j - coins[i]];
        }
    }

    cout << dp[K];

    return 0;
}