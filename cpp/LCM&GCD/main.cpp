#include <iostream>

using namespace std;

long N, M;


long gcd (long a, long b){
    if(b==0){
        return a;
    }else{
        return gcd(b, a%b);
    }
}


int main() {
    cin >> N >> M;
    if(N < M){
        long temp = N;
        N = M;
        M = temp;
    }

    long ret_gcd = gcd(N,M);

    cout << ret_gcd << "\n" << N*M/ret_gcd;
    return 0;
}