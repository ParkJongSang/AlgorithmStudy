#include <iostream>
#include <algorithm>
#include <limits>

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

    for(int i = 1; i <= 10001; i++){
        dp[i] = 987654321;
    }

    sort(coins+1, coins+N+1);
    dp[0] = 0;
    for(int i = 1; i <= N; i++){
        for(int j = coins[i]; j <= K; j++){
            dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        }
    }

    if(dp[K] == 987654321){
        cout << -1;
    }else{
        cout << dp[K];
    }
    return 0;
}