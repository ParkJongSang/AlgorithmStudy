#include <iostream>

using namespace std;

int N, X;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> X;

    int *arr = new int[N];

    for(int i = 0; i < N; i++){
        cin >> arr[i];
        if(arr[i] < X){
            cout << arr[i] << " ";
        }
    }

    return 0;
}