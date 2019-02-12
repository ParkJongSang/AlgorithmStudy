#include <iostream>

using namespace std;

int num[1025][1025] = {0, };
int dp[1025][1025] = {0, };
int x1, x2, y1, y2;
int N, M;

int solve(int a, int b, int c, int d){
    int ret = 0;
    for(int i = a; i <= c; i++){
        ret += dp[i][d] - dp[i][b-1];
    }
    return ret;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> num[i][j];
        }
    }

    for(int i = 1; i <= N; i++){
        dp[i][1] = num[i][1];
        for(int j = 2; j <= N; j++){
            dp[i][j] = dp[i][j-1] + num[i][j];
        }
    }

    for(int i = 0; i < M; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        cout << solve(x1, y1, x2, y2) << "\n";
    }


    return 0;
}