#include <iostream> 

using namespace std;

long long dp[100001];
int N;
long long arr[100001];
long long ans;

int main(void){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }
    dp[1] = arr[1];
    ans = arr[1];
    for(int i = 2; i <= N; i++){
        dp[i] = max(dp[i-1] + arr[i], arr[i]);
        if(ans < dp[i]){
            ans = dp[i];
        }
    }
    cout << ans << "\n";
    return 0;
}