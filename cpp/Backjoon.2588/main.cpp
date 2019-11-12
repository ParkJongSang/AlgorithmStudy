#include <iostream>

using namespace std;

int main(void){
    int N, M;
    int a, b, c;
    int ans;

    cin >> N >> M;

    ans = N * M;
    a = M / 100;
    M = M % 100;
    b = M / 10;
    M = M % 10;
    c = M;

    cout << N * c << endl;
    cout << N * b << endl;
    cout << N * a << endl;
    cout << ans << endl;
    
    return 0;
}