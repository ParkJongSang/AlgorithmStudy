#include <iostream>

using namespace std;

long long dp[101] = {0, 1, 1, 1, };
int N;

int main() {
    int tc;
    cin >> tc;

    for(int j = 4; j < 101; j++){
        dp[j] = dp[j-3] + dp[j-2];
    }

    for(int i = 0; i < tc; i++){
        cin >> N;
        cout << dp[N] << "\n";
    }

    return 0;
}