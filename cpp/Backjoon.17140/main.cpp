#include <cstdio>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int board[100][100];
int max_R = 3;
int max_C = 3;

struct info{
    int num;
    int cnt;
};

bool Is_Inside(int y, int x){
    if(y >= 0 && y < 100 && x >= 0 && x < 100){
        return true;
    }
    return false;
}

bool cmp(info a, info b){
    if(a.cnt == b.cnt){
        return a.num < b.num;
    }
    return a.cnt < b.cnt;
}

void debug(){
    printf("=======================\n");
    for(int i = 0; i < max_C; i++){
        for(int j = 0; j < max_R; j++){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int solve(int R, int C, int T){
    int ret = 0;

    while(1){
        //printf("%d %d %d\n", ret, max_C, max_R);
        //debug();
        if(ret > 100){
            return -1;
        }
        if(board[R][C] == T){
            break;
        }
        if(max_C >= max_R){
            //R연산
            //printf("R %d %d\n", max_C, max_R);
            int cur_max_R = 0;
            for(int i = 0; i < max_C; i++){
                int cnt_sort[101] = {0, };
                vector<info> v;
                int cur_R = 0;
                for(int j = 0; j < max_R; j++){
                    if(board[i][j] > 0) cnt_sort[board[i][j]]++;
                }
                for(int j = 0; j < 101; j++){
                    if(cnt_sort[j] > 0){
                        info tmp = {j, cnt_sort[j]};
                        v.push_back(tmp);
                    }
                }
                sort(v.begin(), v.end(), cmp);
                for(int j = 0; j < 100; j++){
                    board[i][j] = 0;
                }
                for(int j = 0; j < v.size(); j++){
                    if(cur_R < 100) board[i][cur_R++] = v[j].num;
                    if(cur_R < 100) board[i][cur_R++] = v[j].cnt;
                }
                cur_max_R = max(cur_max_R, cur_R);
            }
            max_R = cur_max_R;
        }else{
            //C연산
            //printf("C %d %d\n", max_C, max_R);
            int cur_max_C = 0;
            for(int i = 0; i < max_R; i++){
                int cnt_sort[101] = {0, };
                vector<info> v;
                int cur_C = 0;
                for(int j = 0; j < max_C; j++){
                    if(board[j][i] > 0) cnt_sort[board[j][i]]++;
                }
                for(int j = 1; j < 101; j++){
                    if(cnt_sort[j] > 0){
                        info tmp = {j, cnt_sort[j]};
                        v.push_back(tmp);
                    }
                }
                sort(v.begin(), v.end(), cmp);
                for(int j = 0; j < 100; j++){
                    board[j][i] = 0;
                }
                for(int j = 0; j < v.size(); j++){
                    if(cur_C < 100) board[cur_C++][i] = v[j].num;
                    if(cur_C < 100) board[cur_C++][i] = v[j].cnt;
                }
                cur_max_C = max(cur_max_C, cur_C);
            }
            max_C = cur_max_C;
        }
        ret++;
    }

    return ret;
}

int main(void){
    int R, C, T;
    scanf("%d %d %d", &R, &C, &T);
    for(int y = 0; y < 3; y++){
        for(int x = 0; x < 3; x++){
            scanf("%d", &board[y][x]);
        }
    }
    printf("%d\n", solve(R-1, C-1, T));
    return 0;
}