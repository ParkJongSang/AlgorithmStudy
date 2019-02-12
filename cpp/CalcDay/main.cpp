#include <iostream>
//(1 ≤ E ≤ 15, 1 ≤ S ≤ 28, 1 ≤ M ≤ 19)
using namespace std;

int E, S, M;

int solve(int E, int S, int M){
    // x에 대하여
    // x % 15 == E, x % 28 == S, x % M == M
    int a = 1, b = 1, c = 1;
    for(int i = 1; i <= 7980; i++ ){
        if(a == E && b == S && c == M){
            return i;
        }
        a+=1; b+=1; c+=1;
        if(a > 15){
            a = 1;
        }
        if(b > 28){
            b = 1;
        }
        if(c > 19){
            c = 1;
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> E >> S >> M;
    cout << solve(E, S, M);

    return 0;
}

