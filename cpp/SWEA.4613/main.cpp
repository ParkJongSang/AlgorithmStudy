#include <iostream>
#include <stdio.h>

const int dx[4] = {0,0,-1,1};
const int dy[4] = {1,-1,0,0};

using namespace std;

int ans = 0;
int N, tc;
int T = 10;
int map[100][100];
int visit[100][100];

int init(){
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            map[i][j] = 0;
            visit[i][j] = 0;
        }
    }
    ans = 0;
}

bool is_inside(int y, int x){
    if(y >= 0 && y < 100 && x >= 0 && x < 100){
        return true;
    }
    return false;
}

void dfs(int y, int x){
    visit[y][x] = 1;
    if(map[y][x] == 3){
        ans = 1;
        return;
    }

    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(is_inside(ny, nx) && visit[ny][nx] == 0 && map[ny][nx] != 1){
            dfs(ny, nx);
        }
    }
}

int main(void){

    for(int T = 1; T <= 10; T++){
        cin >> tc;
        init();
        for(int i = 0; i < 100; i++){
            for(int j = 0; j < 100; j++){
                scanf("%1d", &map[i][j]);
            }
        }  
        dfs(1, 1);
        cout << "#" << T << " " << ans << "\n";
    }

    return 0;
}