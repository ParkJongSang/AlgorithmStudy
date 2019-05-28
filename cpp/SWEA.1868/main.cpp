#include <iostream>
#include <string>

using namespace std;

const int dir[8][2]={
    {1,0},{1,-1},{1,1},
    {0,1},{0,-1},
    {-1,0},{-1,-1},{-1,1}
};
const char num_to_char[10] = { '0','1','2','3','4','5','6','7','8','9' };
char map[302][302];
int N;
int cnt = 900;

void debug(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << map[i][j] << " ";
        }
        cout <<"\n";
    }
    cout << "\n";
}

bool is_inside(int x, int y){
    if(x >= 0 && x < N && y >= 0 && y < N){
        return true;
    }
    return false;
}

void init(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            map[i][j] = '.';
        }
    }
}

int search_bomb(int y, int x){
    int ret = 0;
    for(int i = 0; i < 8; i++){
        if(is_inside(y+dir[i][0], x+dir[i][1]) && map[y+dir[i][0]][x+dir[i][1]] == '*'){
            ret += 1;
        }
    }
    //cout << ret;
    return ret;
}

void input(){
    char c;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> c;
            map[i][j] = c;
        }
    }
}

void dfs(int y, int x, int cnt){
    for(int i = y; i < N ; i++){
        for(int j = x; j < N; j++){
            int nx = x+dir[i][1];
            int ny = y+dir[i][0];
            if(is_inside(ny, nx) && map[ny][nx] == '.'){
                
            }
        }
        x = 1;
    }
}

int main(void){
    int tc;
    cin >> tc;
    for(int i = 1; i <= tc; i++){
        cin >> N;
        input();

    }
}