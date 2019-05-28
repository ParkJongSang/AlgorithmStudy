#include <iostream>
#include <algorithm>

using namespace std;

int ladder[11][31] = {0, };
int N, M, H;
int ans = 4;

bool is_same_line(){
    for(int i = 1; i < N; i++){
        int top = i;
        int cur = i;
        for(int j = 1; j <= H; j++){
            if(ladder[cur][j] == 1){
                cur += 1;
            }else if(ladder[cur-1][j] == 1){
                cur -= 1;
            }
        }
        if(top != cur) return false;
    }

    return true;
}

void print_ladder(){
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= N; j++){
            cout << ladder[j][i] << " ";
        }cout << "\n";
    }cout << "\n";
}

void dfs(int a, int b, int cnt){
    if(cnt > 3) return;

    if(is_same_line()){
        ans = min(ans, cnt);
        return;
    }

    for(int i = a; i <= N; i++){
        for(int j = b; j <= H; j++){
            if(ladder[i][j] == 0 && ladder[i-1][j] != 1 && ladder[i+1][j] != 1){
                ladder[i][j] = 1;
                dfs(i, j+1, cnt+1);
                ladder[i][j] = 0;
            }
        }
        b = 1;
    }

}

int main(void){
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M >> H;

    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        ladder[b][a] = 1;
    }

    dfs(1,1,0);

    if(ans > 3){
        cout << -1;
    }else{
        cout << ans;
    }
    return 0;
}