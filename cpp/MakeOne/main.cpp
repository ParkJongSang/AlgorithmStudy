#include <iostream>

using namespace std;

int N;
int dp[1000001] = {0, 0, 1, 1, };

//top_down + memoization하다가 종료코드 11나옴
//bottom_up방식도 있다는 것을 기억할것

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    for(int i = 4; i < 1000001; i++){
        dp[i] = dp[i-1] + 1;
        if(i % 2 == 0){
            dp[i] = min(dp[i], dp[i/2]+1);
        }
        if(i % 3 == 0){
            dp[i] = min(dp[i], dp[i/3]+1);
        }
    }

    cin >> N;
    cout << dp[N];
    return 0;
}