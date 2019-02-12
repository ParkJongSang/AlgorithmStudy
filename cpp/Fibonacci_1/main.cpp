#include <iostream>

using namespace std;

int dp[46] = {0, 1, 1, };
int N;

int main() {

    for(int i = 3; i < 46; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    cin >> N;

    cout << dp[N];
    return 0;
}