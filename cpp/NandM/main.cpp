#include <iostream>
#include <algorithm>

using namespace std;
int N, M;
int arr[9];
int check[9];

void solve(int pos){
    if(pos == M){
        for(int i = 0; i < M; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = 1; i <= N; i++) {
        if (check[i] == 0) {
            arr[pos] = i;
            check[i] = 1;
            solve(pos + 1);
            arr[pos] = 0;
            check[i] = 0;
        }
    }
    return;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    solve(0);
    return 0;
}