#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
 
#define endl "\n"
#define MAX 50 + 1
#define PLAYER_NUM 10
using namespace std;
 
int N, Answer;
int Order[PLAYER_NUM];      
int Game[MAX][PLAYER_NUM];  
bool visit[PLAYER_NUM];    
 
void Input(){
    cin >> N;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j < PLAYER_NUM; j++){
            cin >> Game[i][j];
        }
    }
}
 
void Play_The_Game(){
    /* 실제로 게임을 진행해보기 위한 함수 */
    int Score = 0;
    int Start_Player = 1;
    int Base_State[4];    
 
    for (int i = 1; i <= N; i++){
        int Out_Cnt = 0;
        bool Next_Ining = false;
        memset(Base_State, 0, sizeof(Base_State));
 
        while (1){
            for (int j = Start_Player; j < PLAYER_NUM; j++){
                int Player = Game[i][Order[j]];
                if (Player == 0) Out_Cnt++;       
                else if (Player == 1){
                    for (int F = 3; F >= 1; F--){
                        if (Base_State[F] == 1){
                            if (F == 3){
                                Base_State[F] = 0;
                                Score++;
                            }else{
                                Base_State[F + 1] = 1; // 3루가 아닌 선수들은 1루씩 전진
                                Base_State[F] = 0;     
                            }
                        }
                    }
                    Base_State[1] = 1;
                }else if (Player == 2){
                    for (int F = 3; F >= 1; F--){
                        if (Base_State[F] == 1){
                            if (F == 3 || F == 2){
                                Base_State[F] = 0;
                                Score++;
                            }else{
                                Base_State[F + 2] = 1;
                                Base_State[F] = 0;
                            }
                        }
                    }
                    Base_State[2] = 1;
                }else if (Player == 3){
                    for (int S = 3; S >= 1; S--){
                        if (Base_State[S] == 1){
                            Base_State[S] = 0;
                            Score++;
                        }
                    }
                    Base_State[3] = 1;
                }else{
                    for (int F = 1; F <= 3; F++) {
                        if (Base_State[F] == 1){
                            Base_State[F] = 0;
                            Score++;
                        }
                    }
                    Score++;
                }
                if (Out_Cnt == 3){
                    Start_Player = j + 1;
                    if (Start_Player == PLAYER_NUM) Start_Player = 1;
                    Next_Ining = true;
                    break;
                }
            }
            if (Next_Ining == true) break;
            Start_Player = 1;
        }
    }
    Answer = max(Answer, Score);
}
 
void DFS(int Cnt){
    if (Cnt == PLAYER_NUM){
        Play_The_Game();
        return;
    }
 
    for (int i = 1; i < PLAYER_NUM; i++){
        if (visit[i] == true) continue;
        visit[i] = true;
        Order[i] = Cnt;
        DFS(Cnt + 1);
        visit[i] = false;
    }
}
 
void Solution(){
    visit[4] = true;   
    Order[4] = 1; 
    DFS(2);
    cout << Answer << endl;
}
 
void Solve(){
    Input();
    Solution();
}
 
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 

    Solve();
 
    return 0;
}