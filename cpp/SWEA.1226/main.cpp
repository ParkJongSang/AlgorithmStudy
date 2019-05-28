#include <iostream>

using namespace std;

const int dx[4] = {0,0,-1,1};
const int dy[4] = {1,-1,0,0};

int map[16][16];
int visit[16][16];
int result;
int char_to_int[4] = {0, 1, 2, 3};

void init(){
    for(int i = 0; i < 16; i++){
        for(int j = 0; j < 16; j++){
            map[i][j] = -1;
            visit[i][j] = 0;
        }
    }
}
void debug(){
    cout << "\n";
    for(int i = 0; i < 16; i++){
        for(int j = 0; j < 16; j++){
            cout << map[i][j];
        }
        cout << "\n";
    }
}

void debug_visit(){
    cout << "\n";
    for(int i = 0; i < 16; i++){
        for(int j = 0; j < 16; j++){
            cout << visit[i][j];
        }
        cout << "\n";
    }
}

bool is_inside(int y, int x){
    if(y >= 0 && y < 16 && x >= 0 && x < 16){
        return true;
    }
    return false;
}

void dfs(int y, int x){
    if(map[y][x] == 3){
        result = 1;
        return;
    }
    //debug_visit();
    visit[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(is_inside(ny, nx) && map[ny][nx] != 1 &&visit[ny][nx] == 0){
            dfs(ny, nx);
        }
    }
    return;
}

int main(void){
    int count = 10;
    int tc;

    while(count--){
        cin >> tc;
        init();
        result = 0;
        for(int i = 0; i < 16; i++){
            for(int j = 0; j < 16; j++){
                char temp;
                cin >> temp;
                map[i][j] = temp-'0';
            }
        }
        //debug();
        dfs(1,1);
        cout << "#" << tc << " " << result << "\n";
    }
    return 0;
}