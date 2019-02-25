#include <iostream>
#include <queue>

using namespace std;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int visit[50][50];
int map[50][50];

int N, M, K, X, Y;
int ret;

struct Point{
    int y;
    int x;
};

//입력이 항상 잘 들어 갔는지 확인할 것
//입력 ㅈ같이 받았다가 ㅈ된 문제

void init(){
    for(int i = 0; i < 50; i++){
        for(int j = 0; j < 50; j++){
            map[i][j] = 0;
            visit[i][j] = 0;
        }
    }
    ret = 0;
}

bool is_inside(int y, int x){
    if(y >= 0 && y < M && x >= 0 && x < N){
        return true;
    }return false;
}

void dfs(int y, int x){
    visit[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(is_inside(ny, nx) && map[ny][nx] == 1 && visit[ny][nx] == 0){
            visit[ny][nx] = 1;
            dfs(ny, nx);
        }
    }
}

void debug(){
    cout << endl;
    for(int y = 0; y < M; y++){
        for(int x = 0; x < N; x++){
            cout << map[y][x] << " ";
        }cout << endl;
    }cout << endl;
}

int main(void){
    int tc;
    cin >> tc;

    while(tc--){
        cin >> N >> M >> K;
        init();
        for(int i = 0; i < K; i++){
            int x; int y;
            cin >> x >> y;
            map[y][x] = 1;
        }

        //debug();

        for(int y = 0; y < M; y++){
            for(int x = 0; x < N; x++){
                if(map[y][x] == 1 && visit[y][x] == 0){
                    dfs(y, x);
                    ret += 1;
                }
            }
        }

        cout << ret << "\n";
    }

    return 0;
}