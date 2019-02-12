#include <iostream>
#include <algorithm>

using namespace std;

int N;
int tc;
int arr[100001][2] = {0, };
int dp[100001][2] = {0, };

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> tc;

    for(int i = 0; i < tc; i++){
        cin >> N;
        for(int y = 0; y <= 1; y++){
            for(int x = 1; x <= N; x++){
                cin >> arr[x][y];
            }
        }

        dp[1][0] = arr[1][0]; dp[1][1] = arr[1][1];
        dp[2][0] = dp[1][1] + arr[2][0];
        dp[2][1] = dp[1][0] + arr[2][1];

        for(int k = 3; k <= N; k++){
            dp[k][0] = max(dp[k-1][1] + arr[k][0], max(dp[k-2][1] + arr[k][0], dp[k-2][0] + arr[k][0]));
            dp[k][1] = max(dp[k-1][0] + arr[k][1], max(dp[k-2][1] + arr[k][1], dp[k-2][0] + arr[k][1]));
        }

        cout << max(dp[N][0], dp[N][1]) << "\n";
    }

    return 0;
}