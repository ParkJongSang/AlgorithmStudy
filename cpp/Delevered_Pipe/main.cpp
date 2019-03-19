#include <iostream>

using namespace std;

int dp[32][32];
int map[32][32];
int visit[32][32];
int N;
int ans = 0;

void debug(void){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << dp[i][j] << " ";
        }cout << endl;
    }cout << endl;
}

bool is_inside(int y, int x){
    if(y < 0 || y >= N || x < 0 || x >= N){
        return false;
    }
    return true;
}

int solve(int y, int x, int state){
    if(y == N-1 && x == N-1){
        dp[y][x] += 1;
        return dp[y][x];
    }

    if(y != 0 && x != 1 && dp[y][x] != 0){
        return dp[y][x];
    }

    if(dp[y][x] == 0){
        dp[y][x] = 1;
    }

    if(state == 0){
        //가로상태
        if(is_inside(y, x+1) && visit[y][x+1] == 0 && map[y][x+1] == 0){
            visit[y][x+1] = 1;
            dp[y][x] = solve(y, x+1, 0) + 1;
            visit[y][x+1] = 0;
        }
        if(is_inside(y+1, x+1) && visit[y+1][x+1] == 0 && map[y][x+1] == 0 && map[y+1][x] == 0 && map[y+1][x+1] == 0){
            visit[y+1][x+1] = 1;
            dp[y][x] = solve(y+1, x+1, 2) + 1;
            visit[y+1][x+1] = 0;
        }
    }
    if(state == 1){
        //세로상태
        if(is_inside(y+1, x) && visit[y+1][x] == 0 && map[y+1][x] == 0){
            visit[y+1][x] = 1;
            dp[y][x] = solve(y+1, x, 1) + 1;
            visit[y+1][x] = 0;
        }
        if(is_inside(y+1, x+1) && visit[y+1][x+1] == 0 && map[y][x+1] == 0 && map[y+1][x] == 0 && map[y+1][x+1] == 0){
            visit[y+1][x+1] = 1;
            dp[y][x] = solve(y+1, x+1, 2) + 1;
            visit[y+1][x+1] = 0;
        }
    }
    if(state == 2){
        if(is_inside(y, x+1) && visit[y][x+1] == 0 && map[y][x+1] == 0){
            visit[y][x+1] = 1;
            dp[y][x] = solve(y, x+1, 0) + 1;
            visit[y][x+1] = 0;
        }
        if(is_inside(y+1, x) && visit[y+1][x] == 0 && map[y+1][x] == 0){
            visit[y+1][x] = 1;
            dp[y][x] = solve(y+1, x, 1) + 1;
            visit[y+1][x] = 0;
        }
        if(is_inside(y+1, x+1) && visit[y+1][x+1] == 0 && map[y][x+1] == 0 && map[y+1][x] == 0 && map[y+1][x+1] == 0){
            visit[y+1][x+1] = 1;
            dp[y][x] = solve(y+1, x+1, 2) + 1;
            visit[y+1][x+1] = 0;
        }
    }
    return dp[y][x];
}

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
        }
    }

    visit[0][0] = 1;
    visit[0][1] = 1;
    solve(0, 1, 0);

    debug();

    cout << dp[0][1] << endl;

    return 0;
}