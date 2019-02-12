#include <iostream>
#include <algorithm>

using namespace std;
int N, M;
int arr[9];
int ret[9];
int check[9];

void solve(int y){
    if(y == M){
        for(int i = 0; i < M; i++){
            cout << ret[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = 0; i < N; i++) {
        if(check[i] == 0){
            check[i] = 1;
            ret[y] = arr[i];
            solve(y + 1);
            ret[y] = 0;
            check[i] = 0;
        }
    }
    return;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    sort(arr, arr+N);

    solve(0);

    return 0;
}