#include <iostream>

using namespace std;

long long N, P, Q;
long long arr[1000000];

long long dp(long long n){
    if(n < 1000000 && arr[n] != 0){
        return arr[n];
    }
    if(n == 0) {
        arr[0] = 1;
        return 1;
    }
    if(n == 1){
        arr[1] = 2;
        return 2;
    }
    long long ans = dp(n/P) + dp(n/Q);

    if(n < 1000000){
        arr[n] = ans;
    }

    return ans;
}

int main() {
    cin >> N >> P >> Q;
    cout << dp(N);
    return 0;
}