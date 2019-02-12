#include <iostream>

using namespace std;

int dp[1001] = {0, 1, 3, };
int N;
int main() {
    for(int i = 3; i < 1001; i++){
        dp[i] = (dp[i-1] + 2*dp[i-2]) % 10007;
    }

    cin >> N;
    cout << dp[N];
    return 0;
}