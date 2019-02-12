#include <iostream>

using namespace std;

int N;
int color[1001][3];
int dp[1001][3];

int min(int a, int b, int c){
    return min(a, min(b, c));
}

int main() {
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> color[i][0] >> color[i][1] >> color[i][2];
    }

    dp[1][0] = color[1][0]; dp[1][1] = color[1][1]; dp[1][2] = color[1][2];



    for(int i = 2; i <= N; i++){
        dp[i][0] = min(dp[i-1][1] + color[i][0], dp[i-1][2] + color[i][0]);
        dp[i][1] = min(dp[i-1][0] + color[i][1], dp[i-1][2] + color[i][1]);
        dp[i][2] = min(dp[i-1][0] + color[i][2], dp[i-1][1] + color[i][2]);
    }

    cout << min(dp[N][0], dp[N][1], dp[N][2]);

    return 0;
}