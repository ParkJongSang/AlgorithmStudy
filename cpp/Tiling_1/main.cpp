#include <iostream>

using namespace std;

int dp[1001] = {0, 1, 2, };
int N;
int main() {
    for(int i = 3; i < 1001; i++){
        dp[i] = (dp[i-2] + dp[i-1]) % 10007;
    }
    cin >> N;
    cout << dp[N];
    return 0;
}