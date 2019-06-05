#include <cstdio>

struct Point{
    int y;
    int x;
};

const int dx[4] = {0,0,1,-1};
const int dy[4] = {1,-1,0,0};

Point q[10030000];
int front = 0;
int rear = 0;
int board[1001][1001];
int visit[1001][1001];
int M, N;
int day;

int max(int a, int b){
    if(a>b) return a;
    return b;
}

bool check(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(board[i][j] == 0) return false; 
            day = max(day, board[i][j]);
        }
    }
    return true;
}

bool is_inside(int y, int x){
    if(y >= 1 && y <= N && x >= 1 && x <= M){
        return true;
    }
    return false;
}

void bfs(){
    while(front != rear){
        int cy = q[front].y;
        int cx = q[front].x;
        front++;
        for(int i = 0; i < 4; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(is_inside(ny, nx) && visit[ny][nx] == 0 && board[ny][nx] == 0){
                board[ny][nx] = board[cy][cx] + 1;;
                visit[ny][nx] = 1;
                q[rear].y = ny;
                q[rear].x = nx;
                rear++;
            }
        }
    }
}
int main(void){
    scanf("%d %d", &M, &N);
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            scanf("%d", &board[i][j]);
            if(board[i][j] == 1){
                q[rear].y = i;
                q[rear].x = j;
                rear++;
            }
        }
    }
    bfs();
    //debug();
    if(check()){
        printf("%d\n", day-1);
    }else{
        printf("-1\n");
    }
    return 0;
}