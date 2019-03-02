#include <iostream>

using namespace std;

int N, K;
int A[10][10];
int visit[10];
int pattern[3][21];
int win_cnt[3];
int is_playing[3] = {1,1,0};
int ans = 0;

void init(){
    for(int i = 0; i < 21; i++){
        pattern[0][i] = -1;
    }
}

void debug_pattern(int k){
    cout << "=====================" << endl;
    for(int i = 1; i <= 20; i++){
        cout << pattern[k][i] << " ";
    }cout << endl;
}

void reset_is_playint(){
    is_playing[0] = 1;
    is_playing[1] = 1;
    is_playing[2] = 0;
    win_cnt[0] = 0;
    win_cnt[1] = 0;
    win_cnt[2] = 0;
}

int check_win(int i, int i_idx, int j ,int j_idx){
    if(A[pattern[i][i_idx]][pattern[j][j_idx]] == 2){
        win_cnt[i] += 1;
        return i;
    }else if(A[pattern[i][i_idx]][pattern[j][j_idx]] == 0){
        win_cnt[j] += 1;
        return j;
    }else if(A[pattern[i][i_idx]][pattern[j][j_idx]] == 1){
        if(i > j){
            win_cnt[i] += 1;
            return i;
        }else{
            win_cnt[j] += 1;
            return j;
        }
    }
    return -1;
}

int next_game(){
    for(int i = 0; i < 3; i++){
        if(is_playing[i] == 0){
            is_playing[i] = 1;
            return i;
        }
    }
    return -1;
}

int is_end(){
    for(int i = 0; i < 3; i++){
        if(win_cnt[i] == K){
            return i;
        }
    }
    return -1;
}

void play_game(){
    bool flag = false;
    int first = 0;
    int second = 1;
    int idx[3] = {1, 1, 1};
    while(1){
        if(flag){
            reset_is_playint();
            break;
        }
        
        int winner = check_win(first, idx[first], second, idx[second]);
        if(idx[0] > N || idx[1] > 20 || idx[2] > 20){
            reset_is_playint();
            return;
        }
        if(is_end() == 0){
            ans = 1;
            flag = true;
            return;
        }else if(is_end() != -1){
            flag = true;
        }

        int next_player = next_game();

        idx[first] += 1;
        idx[second] += 1;

        if(winner == first){
            is_playing[second] = 0;
            second = next_player;
        }else if(winner == second){
            is_playing[first] = 0;
            first = next_player;
        }

    }
}

void dfs(int depth){
    if(ans == 1){
        return;
    }
    if(depth > N){
        play_game();
        return;
    }
    for(int i = 1; i <= N; i++){
        if(visit[i] == 0){
            visit[i] = 1;
            pattern[0][depth] = i;
            dfs(depth+1);
            pattern[0][depth] = 0;
            visit[i] = 0;
        }
    }
    return;
}

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> A[i][j];
        }
    }
    init();
    for(int i = 1; i <= 2; i++){
        for(int j = 1; j <= 20; j++){
            cin >> pattern[i][j];
        }
    }

    dfs(1);

    cout << ans;

    return 0;
}