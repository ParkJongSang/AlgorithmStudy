#include <iostream>

using namespace std;

long solve(int n);

int main() {
    int n;
    cin >> n;

    cout << solve(n);

    return 0;
}

long solve(int n){
    long arr[91];
    arr[0] = 0; arr[1] = 1;
    for(int i = 2; i < 91; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    return arr[n];
}