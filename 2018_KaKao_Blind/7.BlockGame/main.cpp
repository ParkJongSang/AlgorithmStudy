#include <string>
#include <vector>
#include <iostream>

using namespace std;

int width;
int height;

bool is_Inside(int y, int x, int height, int width){
    if(y >= 0 && y < height && x >= 0 && x < width){
        return true;
    }
    return false;
}

bool check_up(vector<vector<int>> &board, int n, int y, int x){
    int height = y;
    bool ret = true;
    while(height > 0){
        if(board[height-1][x] == n){
            height--;
            continue;
        }
        if(board[height-1][x] > 0 && board[height-1][x] != n){
            ret = false;
            break;
        }
        height--;
    }
    return ret;
}
bool check_1(vector<vector<int>> &board, int n, int y, int x){
    if(is_Inside(y, x, height, width) && is_Inside(y, x+1, height, width) && is_Inside(y, x+2, height, width) && is_Inside(y-1, x, height, width)){
        if(check_up(board, n, y, x+1) && check_up(board, n, y, x+2)){
            //ㄴ
            if(board[y][x] == n && board[y-1][x] == n && board[y][x+1] == n && board[y][x+2] == n){
                board[y][x] = 0; board[y-1][x] = 0; board[y][x+1] = 0; board[y][x+2] = 0;
                return true;
            }
        }
        if(check_up(board, n, y, x) && check_up(board, n, y, x+1)){
            //__|
            if(board[y][x] == n && board[y][x+1] == n && board[y][x+2] == n && board[y-1][x+2] == n){
                board[y][x] = 0; board[y][x+1] = 0; board[y][x+2] = 0; board[y-1][x+2] = 0;
                return true;
            }
        }
        if(check_up(board, n, y, x) && check_up(board, n, y, x+2)){
            //ㅗ
            if(board[y][x] == n && board[y][x+1] == n && board[y][x+2] == n && board[y-1][x+1] == n){
                board[y][x] = 0; board[y][x+1] = 0; board[y][x+2] = 0; board[y-1][x+1] = 0;
                return true;
            }
        }
    }
    return false;
}

bool check_2(vector<vector<int>> &board, int n, int y, int x){
    if(is_Inside(y, x, height, width) && is_Inside(y, x+1, height, width) && is_Inside(y-1, x, height, width) && is_Inside(y-2, x, height, width)){
        if(check_up(board, n, y, x+1)){
            //|_
            if(board[y][x] == n && board[y-1][x] == n && board[y-2][x] == n && board[y][x+1] == n){
                board[y][x] = 0; board[y-1][x] = 0; board[y-2][x] = 0; board[y][x+1] = 0;
                return true;
            }
        }
        if(check_up(board, n, y, x)){
            //_|
            if(board[y][x] == n && board[y][x+1] == n && board[y-1][x+1] == n && board[y-2][x+1] == n){
                board[y][x] = 0; board[y][x+1] = 0; board[y-1][x+1] = 0; board[y-2][x+1] = 0;
                return true;
            }
        }
    }
    return false;
}
int solution(vector<vector<int>> board) {
    int answer = 0;
    height = board.size();
    width = board[0].size();
    bool flag = true;
    
    while(flag){
        flag = false;
        for(int y = height-1; y >= 0; y--){
            for(int x = 0; x < width; x++){
                if(board[y][x] != 0){
                    int num = board[y][x];
                    bool chk_1 = check_1(board, num, y, x);
                    bool chk_2 = check_2(board, num, y, x);
                    if(chk_1){
                        //cout << y << " " << x <<endl;
                        flag = true;
                        answer += 1;
                    }
                    if(chk_2){
                        //cout << y << " " << x <<endl;
                        flag = true;
                        answer += 1;
                    }
                }
            }
        }
    }
    
    return answer;
}