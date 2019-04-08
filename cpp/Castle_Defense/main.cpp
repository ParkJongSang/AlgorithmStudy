#include <iostream>

using namespace std;

int N, M, D;
int back_up[16][15];
int map[16][15];
int ans = 0;

int max(int a, int b){
    if(a > b){
        return a;
    }
    return b;
}

int abs(int a){
    if(a < 0){
        return (-1) * a;
    }
    return a;
}

void clone(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            back_up[i][j] = map[i][j];
        }
    }
}

void roll_back(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            map[i][j] = back_up[i][j];
        }
    }
}

bool shot(int archer_y, int archer_x){
    int dist;
    int will_die_dist = 50;
    int will_die_y = -1;
    int will_die_x = -1;
    for(int i = N-1; i >= 0; i--){
        for(int j = 0; j < M; j++){
            dist = abs(archer_y-i) + abs(archer_x-j);
            if(map[i][j] != 0 && dist <= D){
                if(will_die_y == -1 && will_die_x == -1){
                    will_die_y = i;
                    will_die_x = j;
                    will_die_dist = dist;
                }else if(will_die_dist > dist){
                    will_die_y = i;
                    will_die_x = j;
                    will_die_dist = dist;
                }
                else if(will_die_dist == dist){
                    if(will_die_x > j){
                        will_die_y = i;
                        will_die_x = j;
                        will_die_dist = dist;
                    }
                }
            }
        }
    }
    if(will_die_y == -1 && will_die_x == -1 && will_die_dist == 50){
        return false;
    }
    map[will_die_y][will_die_x] = 3;
    return true;
}

bool game_over(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j] == 1){
                return false;
            }
        }
    }
    return true;
}

void down(){
    for(int i = N-1; i >= 1; i--){
        for(int j = 0; j < M; j++){
            if(i == N-1 && map[i][j] == 1){
                map[i][j] = 0;
            }
            if(map[i][j] == 0 && map[i-1][j] == 1){
                map[i][j] = 1;
                map[i-1][j] = 0;
            }
        }
    }
}

int delete_enemy(){
    int ret = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j] == 3){
                map[i][j] = 0;
                ret += 1;
            }
        }
    }
    return ret;
}

int start(){
    int cnt = 0;
    while(!game_over()){
        for(int i = 0; i < M; i++){
            if(map[N][i] == 2){
                shot(N,i);
            }
        }
        cnt += delete_enemy();
        down();
        //debug();
    }
    return cnt;
}

void dfs(int cnt){
    if(cnt >= 3){
        int ret = start();
        ans = max(ans, ret);
        roll_back();
        return;
    }
    for(int i = 0; i < M; i++){
        if(map[N][i] == 0){
            map[N][i] = 2;
            dfs(cnt+1);
            map[N][i] = 0;
        }
    }
}

int main(void){
    cin >> N >> M >> D;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }
    for(int i = 0; i < M; i++){
        map[N][i] = 0;
    }
    clone();
    dfs(0);
    cout << ans << "\n";
    return 0;
}