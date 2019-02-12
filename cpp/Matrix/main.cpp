#include <iostream>
#include <limits>

using namespace std;

int row[501];
int col[501];
int d[501];
long long dp[501][501];
int N;

long long solve(int l, int r){
    //if (dp[l][r]) {
    //    return dp[l][r];
    //}
    //if(l==r){
    //    return 0;
    //}
    //
    //dp[l][r] = numeric_limits<int>::max();
    //
    //for (int i=l; i<r; i++){
    //    dp[l][r] = min(solve(l,i) + solve(i+1,r)+ row[l]*col[i]*col[r], dp[l][r]);
    //}

    return dp[l][r];
}

void solve(int n){
    for(int idx = 0; idx < N; idx++){
        for(int i = 1; i <= N-idx; i++){
            int j = idx + i;
            if(i==j){
                dp[i][j] = 0;
            }else{
                dp[i][j] = numeric_limits<int>::max();
                for(int k = i; k <= j-1; k++){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + d[i-1]*d[k]*d[j]);
                }
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> row[i] >> col[i];
        if(i == 1){
            d[i-1] = row[i];
            d[i] = col[i];
        }else{
            d[i] = col[i];
        }
    }

    //solve(1, N);
    solve(N);
    cout << dp[1][N];
}
