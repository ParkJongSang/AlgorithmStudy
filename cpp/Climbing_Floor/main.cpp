#include <iostream>

using namespace std;

int N;
int floor[301];
int dp[301] = {0, };


int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> floor[i];
    }
    dp[1] = floor[1];
    dp[2] = max(floor[1] + floor[2], floor[2]);
    dp[3] = max(floor[1] + floor[3], floor[2] + floor[3]);

    for(int i = 4; i < 301; i++){
        dp[i] = max(dp[i-2] + floor[i], dp[i-3] + floor[i-1] + floor[i]);
    }

    cout << dp[N];

    return 0;
}