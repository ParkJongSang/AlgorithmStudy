#include <iostream>

using namespace std;

int r = 31;
int M = 1234567891;
//둘은 서로소이다.

int N;
char L[52];

int char2int(char c){
    int ret = (c - 'a') + 1;
    return ret;
}

long long pow(int r, int num){
    long long ret = 1;
    for(int i = 0; i < num; i++){
        ret *= r;
    }
    return ret;
}

long long solve(int length){
    long long cur_int;
    long long to_mul;
    long long ret = 0;
    for(int i = 0; i < length; i++){
        cur_int = char2int(L[i]);
        to_mul = pow(31, i);
        ret += cur_int * to_mul;
    }

    return ret;
}

int main(void){
    cin >> N;
    cin >> L;
    cout << solve(N) << "\n";
    return 0;
}