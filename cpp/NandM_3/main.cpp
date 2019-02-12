#include <iostream>
#include <algorithm>

using namespace std;
int N, M;
int arr[9];

void solve(int y){
    if(y == M){
        for(int i = 0; i < M; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = 1; i <= N; i++) {
        arr[y] = i;
        solve(y + 1);
        arr[y] = 0;
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