#include <iostream>

using namespace std;

int dp[1001][1001];
int arr[1001][1001];
int N, M;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    char input[M+2];
    for(int i = 1; i <= N; i++){
        cin >> input;
        for(int j = 0; j < M; j++){
            arr[i][j+1] = input[j]-'0';
            //cout << arr[i][j];
            if(arr[i][j+1]){
                dp[i][j+1] = arr[i][j+1];
            }
        }
        //cout << "\n";
    }

    int ret = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(arr[i][j] != 0){
                arr[i][j] = min(arr[i-1][j-1], min(arr[i-1][j], arr[i][j-1]))+1;
            }
            if(arr[i][j] > ret){
                ret = arr[i][j];
            }
        }
    }

    cout << ret * ret;


    return 0;
}