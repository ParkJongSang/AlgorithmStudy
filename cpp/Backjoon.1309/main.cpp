#include <iostream>
#define MAX 100000

typedef long long ll;

using namespace std;

int N;
ll dp[MAX+1][2];

int main(void){
    cin >> N;
    dp[1][0] = 1;
    dp[1][1] = 2;

    for(int i = 2; i <= MAX; i++){
        dp[i][0] = (dp[i-1][0] + dp[i-1][1])%9901;
        dp[i][1] = (2*dp[i-1][0] + dp[i-1][1])%9901;
    }

    cout << (dp[N][0]+dp[N][1]) % 9901 << endl;
    return 0;
}