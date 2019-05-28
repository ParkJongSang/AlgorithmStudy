#include <iostream>

using namespace std;

int N, Q;
int arr[100001];
int dp[100001][4];

void reset(){
    for(int i = 1 ; i <= N; i++){
        arr[i] = 0;
        dp[i][1] = 0;
        dp[i][2] = 0;
        dp[i][3] = 0;
    }
}

void init(){
    cin >> N >> Q;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }
}

void solve(){
    dp[1][arr[1]] += 1;
    for(int i = 2; i <= N; i++){
        for(int j = 1; j <= 3; j++){
            if(j == arr[i]){
                dp[i][j] = dp[i-1][j]+1;
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
}

void debug(){
    for(int i = 1; i <= N; i++){
        cout << dp[i][1] << " ";
    }cout << "\n";
    for(int i = 1; i <= N; i++){
        cout << dp[i][2] << " ";
    }cout << "\n";
    for(int i = 1; i <= N; i++){
        cout << dp[i][3] << " ";
    }cout << "\n";
}

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int tc;
    cin >> tc;

    for(int i = 1; i <= tc; i++){
        int left, right;
        init();
        cout << "#" << i << "\n";
        solve();
        //debug();
        for(int j = 0; j < Q; j++){
            cin >> left >> right;
            int first = dp[right][1] - dp[left-1][1];
            int second = dp[right][2] - dp[left-1][2];
            int third = dp[right][3] - dp[left-1][3];

            cout << first << " " << second << " " << third << "\n";
        }
        reset();
    }

}