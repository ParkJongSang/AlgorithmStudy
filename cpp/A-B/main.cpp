#include <iostream>

using namespace std;

int solve(int a, int b);
int N, M;

int main() {
    cin >> N >> M;

    cout << solve(N, M);
    return 0;
}

int solve(int a, int b){
    return a - b;
}