#include <iostream>

using namespace std;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int arr[4][4];
int dp[10][10][10][10][10][10][10];
int num[7];
int cnt;

void debug(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cout << arr[i][j];
        }cout << endl;
    }cout << endl;
}

void reset(){
    for(int i = 0; i < 7; i++) num[i] = 0;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            arr[i][j] = 0;
        }
    }
    for(int a = 0; a < 10; a++){
        for(int b = 0; b < 10; b++){
            for(int c = 0; c < 10; c++){
                for(int d = 0; d < 10; d++){
                    for(int e = 0; e < 10; e++){
                        for(int f = 0; f < 10; f++){
                            for(int g = 0; g < 10; g++){
                                dp[a][b][c][d][e][f][g] = 0;
                            }
                        }
                    }
                }
            }
        }   
    }
    cnt = 0;
}

bool is_inside(int y, int x){
    if(y >= 0 && y < 4 && x >= 0 && x < 4){
        return true;
    }
    return false;
}

bool is_exist(){
    if(dp[num[0]][num[1]][num[2]][num[3]][num[4]][num[5]][num[6]] == 1){
        return true;
    }
    return false;
}

void dfs(int y, int x ,int depth){
    if(depth > 6){
        if(!is_exist()){
            dp[num[0]][num[1]][num[2]][num[3]][num[4]][num[5]][num[6]] = 1;
            cnt += 1;
        }
        return;
    }
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(is_inside(ny, nx)){
            num[depth] = arr[y][x];
            dfs(ny, nx, depth + 1);
            num[depth] = 0;
        }
    }
    return;
}

void solve(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            dfs(i, j, 0);
        }
    }
}

int main(void){
    int tc = 0;
    cin >> tc;

    for(int t = 1; t <= tc; t++){
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                cin >> arr[i][j];
            }
        }

        solve();
        cout << "#" << t << " " << cnt << "\n";
        reset();
    }

    return 0;
}