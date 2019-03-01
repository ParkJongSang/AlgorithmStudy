#include <iostream>

using namespace std;

int board[9][9];

int cmd[8][2]={
    {0,1},
    {0,-1},
    {1,0},
    {-1,0},
    {-1,1},
    {-1,-1},
    {1,1},
    {1,-1}
};

int cur_cmd[2];

int king_y; char king_x;
int stone_y; char stone_x;
int N;
char input_cmd[3];

int cx, cy;

int char_to_int(char input){
    if(input == 'A') return 1;
    if(input == 'B') return 2;
    if(input == 'C') return 3;
    if(input == 'D') return 4;
    if(input == 'E') return 5;
    if(input == 'F') return 6;
    if(input == 'G') return 7;
    if(input == 'H') return 8;
    return -1;
}

char int_to_char(int input){
    if(input == 1) return 'A';
    if(input == 2) return 'B';
    if(input == 3) return 'C';
    if(input == 4) return 'D';
    if(input == 5) return 'E';
    if(input == 6) return 'F';
    if(input == 7) return 'G';
    if(input == 8) return 'H';
    return -1;
}

int check_cmd(char input[3]){
    if(input[0] == 'R'){
        if(input[1] == 'T'){
            return 4;
        }else if(input[1] == 'B'){
            return 6;
        }
        return 0;
    }else if(input[0] == 'L'){
        if(input[1] == 'T'){
            return 5;
        }else if(input[1] == 'B'){
            return 7;
        }
        return 1;
    }else if(input[0] == 'T'){
        return 3;
    }else if(input[0] == 'B'){
        return 2;
    }
    return -1;
}

void reset_cmd(){
    for(int i = 0; i < 3; i++){
        input_cmd[i] = ' ';
    }
}

void debug(){
    cout << endl;
    for(int i = 1; i <= 8; i++){
        for(int j = 1; j <= 8; j++){
            cout << board[i][j] << " ";
        }cout << endl;
    }
}

bool is_inside(int y, int x){
    if(y >= 1 && y < 9 && x >= 1 && x < 9){
        return true;
    }
    return false;
}

bool move_stone(int y, int x, int input_cmd){
    int ny = y + cmd[input_cmd][0];
    int nx = x + cmd[input_cmd][1];
    if(is_inside(ny,nx)){
        board[ny][nx] = 2;
        board[y][x] = 0;
        return true;
    }else{
        return false;
    }
}

bool move_king(int y, int x, int input_cmd){
    int ny = y + cmd[input_cmd][0];
    int nx = x + cmd[input_cmd][1];
    //cout << nx << " " << ny << endl;
    if(is_inside(ny, nx)){
        if(board[ny][nx] == 2){
            if(!move_stone(ny, nx, input_cmd)){
                return false;
            }else{
                board[ny][nx] = 1;
                board[y][x] = 0;
                cy = ny;
                cx = nx;
                return true;
            }
        }else{
            board[ny][nx] = 1;
            board[y][x] = 0;
            cy = ny;
            cx = nx;
            return true;
        }
    }else{
        return false;
    }
}

void debug_cmd(){
    cout << endl;
    for(int i = 0; i < 3; i++){
        cout <<input_cmd[i];
    }cout << check_cmd(input_cmd) << endl;
}


int main(void){
    cin >> king_x >> king_y;
    board[9-king_y][char_to_int(king_x)] = 1;
    cin >> stone_x >> stone_y;
    board[9-stone_y][char_to_int(stone_x)] = 2;

    //debug();
    cx = char_to_int(king_x);
    cy = 9-king_y;

    cin >> N;
    while(N--){
        reset_cmd();
        cin >> input_cmd;
        //debug_cmd();

        if(!move_king(cy, cx, check_cmd(input_cmd))){
            //cout << "not move" << endl;
            //debug();
            continue;
        }
        //debug();
    }
    cout << int_to_char(cx) << 9-cy << endl;

    for(int i = 1; i < 9; i++){
        for(int j = 1; j < 9; j++){
            if(board[i][j] == 2){
                cout << int_to_char(j) << 9-i << endl;
                break;
            }
        }
    }

    return 0;
}