#include <iostream> 
#include <algorithm>

using namespace std;

int tc, N;
int page[501];
int dp[501][501];
int sum[501];

void init(){
    for(int i = 1; i < 501; i++){
        page[i] = 0;
        sum[i] = 0;
        for(int j = 1; j < 501; j++){
            dp[i][j] = 987654321;
        }
    }
}

int solve(int start, int end){
    if(start >= end){
        return 0;
    }
    if(end == start + 1){
        return page[end] + page[start];
    }
    if(dp[start][end] < 987654321){
        return dp[start][end];
    }
    for(int i = start; i < end; i++){
        int tmp = solve(start, i) + solve(i+1, end) + sum[end] - sum[start-1];
        dp[start][end] = min(tmp, dp[start][end]);
    }
    return dp[start][end];
}

int main(void){
    cin >> tc;
    while(tc--){
        init();
        cin >> N;
        for(int i = 1; i < N+1; i++){
            cin >> page[i];
            sum[i] = sum[i-1] + page[i];
        }

        cout << solve(1, N) << endl;
    }
    return 0;
}