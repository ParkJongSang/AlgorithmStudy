
#include <iostream>
 
using namespace std;


const int dy[4] = {0,0,-1,1};
const int dx[4] = {-1,1,0,0};

int map[500][500];
int cache[500][500];
int N;

bool is_inside(int y, int x){
    if(y >= 0 && y < 500 && x >= 0 && x < 500){
        return true;
    }
    return false;
}

int dfs(int y, int x){
    if(cache[y][x] != -1) 
        return cache[y][x];
    cache[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(is_inside(ny,nx) && map[y][x] < map[ny][nx]){
            cache[y][x] = max(cache[y][x], dfs(ny,nx)+1);
        }
    }
    return cache[y][x];
}

int main(void){
    cin >> N;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
            cache[i][j] = -1;
        }
    }
    int ans = -1;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; j++){
            ans = max(ans, dfs(i,j));
        }
    }

    cout << ans << "\n";
    return 0;
}