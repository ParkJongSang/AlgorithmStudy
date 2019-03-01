#include <iostream>
#include <algorithm>

using namespace std;

char map[50][50];
int N, M;
int ans = 64;

char pattern_A[8][8] = {
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'}
};

char pattern_B[8][8] = {
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'}
};

void init(){
    for(int y = 0; y < M; y++){
        for(int x = 0; x < N; x++){
            map[y][x] = ' ';
        }
    }
}

void debug(){
    for(int y = 0; y < N; y++){
        for(int x = 0; x < M; x++){
            cout << map[y][x] << " " ;
        }cout << endl;
    }cout << endl;
}

int check(int y, int x){
    int ret_a = 0;
    int ret_b = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(map[y+i][x+j] != pattern_A[i][j]){
                ret_a++;
            }
            if(map[y+i][x+j] != pattern_B[i][j]){
                ret_b++;
            }
        }
    }
    return min(ret_a, ret_b);
}

void solve(){
    for(int y = 0; y < N - 7; y++){
        for(int x = 0; x < M - 7; x++){
            ans = min(ans, check(y, x));
        }
    }
}

int main(void){
    cin >> N >> M;
    for(int y = 0; y < N; y++){
        for(int x = 0; x < M; x++){
            cin >> map[y][x];
        }
    }
    //debug();
    solve();
    cout << ans;
    return 0;
}