#include <stdio.h>

int N;
int map[20][20];
bool visit[101];
int result;

void visit_reset(){
    for(int i = 0 ; i < 101; i++){
        visit[i] = false;
    }
}

void init(){
    visit_reset();
    result = -1;
}

void solve(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int a = 1; a < N; a++){
                for(int b = 1; b < N; b++){
                    if(j + a <= N-1 
                    && i + a + b <= N-1 
                    && j - b >= 0 
                    && (a + b) * 2 > result){
                        visit_reset();
                        bool is_able = true;
                        int cur_i = i;
                        int cur_j = j;

                        //우측하단
                        for(int n = 0; n < a; n++){
                            cur_i++; cur_j++;

                            if(!visit[map[cur_i][cur_j]]){
                                visit[map[cur_i][cur_j]] = true;
                            }else{
                                is_able = false;
                                break;
                            }
                        }
                        if(!is_able) continue;

                        //좌측하단
                        for(int n = 0; n < b; n++){
                            cur_i++;cur_j--;
                             if(!visit[map[cur_i][cur_j]]){
                                visit[map[cur_i][cur_j]] = true;
                            }else{
                                is_able = false;
                                break;
                            }
                        }
                        if(!is_able) continue;

                        //좌측상단
                        for(int n = 0; n < a; n++){
                            cur_i--;cur_j--;
                             if(!visit[map[cur_i][cur_j]]){
                                visit[map[cur_i][cur_j]] = true;
                            }else{
                                is_able = false;
                                break;
                            }
                        }
                        if(!is_able) continue;

                        //우측상단
                        for(int n = 0; n < b; n++){
                            cur_i--;
                            cur_j++;
                             if(!visit[map[cur_i][cur_j]]){
                                visit[map[cur_i][cur_j]] = true;
                            }else{
                                is_able = false;
                                break;
                            }
                        }
                        if(!is_able) continue;

                        result = 2 * (a+b);
                    }
                }
            }
        }
    }
}

int main(void){
    int test_case;
    scanf("%d", &test_case);

    for(int tc = 1; tc <= test_case; tc++){
        init();

        scanf("%d", &N);
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                scanf("%d", &map[i][j]);
            }
        }

        solve();

        printf("#%d %d\n", tc, result);
    }

    return 0;
}