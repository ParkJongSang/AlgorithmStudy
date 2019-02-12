#include <iostream>

using namespace std;

int health[20];
int delight[20];
int dp[20][101] = {{0, }};
int N;

int solve(int a, int b){
    if(a == N){
        return 0;
    }
    if(dp[a][b]){
        return dp[a][b];
    }
    int ans = dp[a][b];
    if(b - health[a] > 0){
        ans = solve(a+1, b-health[a]) + delight[a];
    }
    ans = max(ans, solve(a+1, b));
    dp[a][b] = ans;

    return ans;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);


    cin >> N;
    for(int i = 0; i < N; i++){cin >> health[i];
    }
    for(int i = 0; i < N; i++){
        cin >> delight[i];
    }

    cout << solve(0, 100);
    return 0;
}