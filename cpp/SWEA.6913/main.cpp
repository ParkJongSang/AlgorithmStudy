#include <iostream>

using namespace std;

int N, M;
int arr[21][21];
int result[21] = {0, };

void reset_arr(){
    for(int i = 0; i < 21; i++){
        result[i] = 0;
        for(int j = 0; j < 21; j++){
            arr[i][j] = 0;
        }
    }
}

void init(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        int cnt = 0;
        for(int j = 1; j <= M; j++){
            cin >> arr[i][j];
            cnt += arr[i][j];
        }
        result[cnt] += 1;
    }
}

void print_winner(){
    for(int i = M; i >= 1; i--){
        if(result[i] != 0){
            cout << result[i] << " " << i << "\n";
            return;
        }
    }
    cout << result[0] << " " << 0 << "\n";
}


int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int tc;
    cin >> tc;

    for(int i = 1; i <= tc; i++){
        reset_arr();
        init();
        cout << "#" << i << " ";
        print_winner();
    }
}