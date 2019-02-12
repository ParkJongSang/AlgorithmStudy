#include <iostream>

using namespace std;

int dp[31][31];
int N,K;

int main() {
    //조합의 갯수 구하는 문제
    //5C3이런거

    for(int i = 1; i < 31; i++){
        dp[i][0] = 1;
        dp[i][1] = i;
        dp[i][i] = 1;
    }

    for(int i = 3; i < 31; i++){
        for(int j = 2; j < i; j++){
            dp[i][j] = (dp[i-1][j-1]+dp[i-1][j]);
        }
    }
    int tc;
    cin >> tc;

    for(int i = 0; i < tc; i++){
        cin >> K >> N;
        cout << dp[N][K] << "\n";
    }
    return 0;
}