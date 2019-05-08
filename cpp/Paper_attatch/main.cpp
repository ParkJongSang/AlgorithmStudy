#include <iostream>

using namespace std;

int map[10][10];
int cnt_square[6] = {0,5,5,5,5,5};
int ans = 25;

int min(int a, int b){
    if(a > b){
        return b;
    }
    return a;
}

bool is_inside(int y, int x){
    if(y >= 0 && y < 10 && x >= 0 && x < 10){
        return true;
    }
    return false;
}

bool squre_inside(int y, int x, int n){
    for(int i = y; i < y+n; i++){
        for(int j = x; j < x+n; j++){
            if(!is_inside(i, j)){
                return false;
            }
            if(map[i][j] == 0 ){
                return false;
            }
        }
    }
    return true;
}

void attatch_square(int y, int x, int n){
    for(int i = y; i < y+n; i++){
        for(int j = x; j < x+n; j++){
            map[i][j] = 0;
        }
    }
}

void detatch_square(int y, int x, int n){
    for(int i = y; i < y+n; i++){
        for(int j = x; j < x+n; j++){
            map[i][j] = 1;
        }
    }
}

void dfs(int y, int x, int cnt){
    int cur_y , cur_x;
    bool flag = false;
    
    for(int i = y; i < 10; i++){
        for(int j = x; j < 10; j++){
            if(map[i][j] == 1){
                cur_y = i;
                cur_x = j;
                flag = true;
                break;
            }
        }
        if(flag) break;
    }

    if(!flag){
        ans = min(ans, cnt);
        return;
    }

    for(int i = 1; i <= 5; i++){
        if(cnt_square[i] > 0 && squre_inside(cur_y, cur_x, i)){
            cnt_square[i]--;
            attatch_square(cur_y, cur_x, i);
            dfs(cur_y, cur_x, cnt + 1);
            detatch_square(cur_y, cur_x, i);
            cnt_square[i]++;
        }
    }
    return
}

int main(void){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cin >> map[i][j];
        }
    }
    dfs(0,0,0);
    if(ans < 25){
        cout << ans << endl;
    }else{
        cout << -1 << endl;
    }
    
    
    return 0;
}