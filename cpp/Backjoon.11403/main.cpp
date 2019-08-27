#include <iostream>

using namespace std;

int N;
int arr[100][100];
int ans[100][100];


void solve(){
    for(int k = 0; k < N; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(arr[i][k] == 1 && arr[k][j] == 1){
                    arr[i][j] = 1;
                }
            }
        }
    }
}

int main(void){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }
    solve();
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}