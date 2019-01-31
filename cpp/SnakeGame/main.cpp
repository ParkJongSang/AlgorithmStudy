#include <iostream>
#include <vector>

using namespace std;

int N;
int K;

int dir[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};
int cur_dir = 0;

class Move{
public:
    int second;
    char direction;
};

class Point{
public:
    int x;
    int y;
    int dir;
};

vector<Move> v;

void moveSnake(int map[][100], int x, int y);
int rotate(char order);
bool isInside(int x, int y);

int main() {
    cin >> N >> K;
    int map[N][N];
    int ans = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            map[i][j] = 0;
        }
    }

    for(int i = 0; i < K; i++){
        int apple_x, apple_y;
        cin >> apple_x >> apple_y;
        map[apple_x][apple_y] = 2;
    }

    int num_of_move;
    cin >> num_of_move;

    for(int i = 0; i < num_of_move; i++){
        Move temp;
        cin >> temp.second;
        cin >> temp.direction;
        v.push_back(temp);
    }
    map[0][0] = 1;

    cout << ans << endl;

    return 0;
}

void moveSnake(int map[][], int x, int y){
    Point head;
    Point tail;
    head.x = 0; head.y = 0; head.dir = 0;
    tail.x = 0; tail.y = 0; tail.dir = 0;
    int body = 0;

    while(!v.empty()){
        int iter = v.front().second;
        char dir = v.front().direction;
        for(int i = 0; i < iter; i++){
            if(isInside(x, y)){
                if(map[x+dir[cur_dir][0]][y+dir[cur_dir][1]] == 1){//

                }
            }else{
                break;
            }
        }
    }
}


int rotate(char order, int dir){
    if(order=='L'){
        if(dir + 1 >= 4){
            return 0;
        }else{
            return dir + 1;
        }
    }else if(order=='D'){
        if(dir - 1 < 0){
            return 3;
        }else{
            return dir - 1;
        }
    }
}

bool isInside(int x, int y ){
    return (x >= 0 && x < N) && (y >= 0 && y < N);
}