#include <iostream>

using namespace std;

const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};

int N, M;
int map[101][101];
int dist[101][101];

char input;

struct Point{
    int y;
    int x;
};

Point q[10000];
int front = 0;
int rear = 0;

bool is_inside(int y, int x){
    if(y >= 1 && y <= N && x >= 1 && x <= M){
        return true;
    }
    return false;
}

void bfs(){
    q[rear].y = 1;
    q[rear].x = 1;
    rear += 1;

    Point cur;
    dist[1][1] = 0;
    while(front != rear){
        cur.y = q[front].y;
        cur.x = q[front].x;
        front += 1;
        for(int i = 0; i < 4; i++){
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];
            if(is_inside(ny, nx) && map[ny][nx] == 1 && dist[ny][nx] > dist[cur.y][cur.x] + 1){
                dist[ny][nx] = dist[cur.y][cur.x] + 1;
                q[rear].y = ny;
                q[rear].x = nx;
                rear += 1;
            }
        }
    }
}

void debug(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cout << dist[i][j] << "\t";
        }cout << endl;
    }
}

int main(void){
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> input;
            map[i][j] = input - '0';
        }
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            dist[i][j] = 987654321;
        }
    }

    bfs();
    cout << dist[N][M] + 1 << "\n";

    return 0;
}