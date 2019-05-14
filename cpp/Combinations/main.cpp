#include <iostream>

using namespace std;

int N, K;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> K;

    if(K > N / 2){
        K = N - K;
    }

    long long a = 1, b = 1;

    for(int i = 0; i < K; i++){
        a *= N - i;
        b *= K - i;
    }
    long long ans = a / b;
    cout << ans << '\n';

    return 0;
}