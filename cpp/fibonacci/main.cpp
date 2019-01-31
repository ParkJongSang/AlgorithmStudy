#include <iostream>

using namespace std;

int main() {
    int dp[41][2] = {{1,0},{0,1}};
    int testcase;
    int input;
    cin >> testcase;

    for(int i = 2; i < 41; i++){
        dp[i][0] = dp[i-1][0] + dp[i-2][0];
        dp[i][1] = dp[i-1][1] + dp[i-2][1];
    }

    for(int i = 0; i < testcase; i++){
        cin >> input;
        cout << dp[input][0] << " " << dp[input][1] << endl;
    }
    return 0;
}