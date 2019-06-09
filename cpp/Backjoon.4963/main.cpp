#include <cstdio>

struct Point{
    int y;
    int x;
};

const int dy[8] = {1,0,-1,0,1,-1,1,-1};
const int dx[8] = {0,1,0,-1,1,-1,-1,1};

int w, h;
Point q[50*50+10];
int front = 0, rear = 0;
int arr[51][51], visit[51][51];

void init(){
    for(int i = 1; i < 51; i++){
        for(int j = 0; j < 51; j++){
            arr[i][j] = 0;
            visit[i][j] = 0;
        }
    }
}

int is_inside(int y, int x){
    if(y >= 1 && y <= h && x >= 1 & x <= w){
        return 1;
    }
    return 0;
}

void bfs(int y, int x){
    front = 0;
    rear = 0;
    q[rear].y = y;
    q[rear].x = x;
    rear++;
    while(front != rear){
        int cy = q[front].y;
        int cx = q[front].x;
        front++;
        for(int i = 0; i < 8; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(is_inside(ny, nx) && arr[ny][nx] == 1 && visit[ny][nx] == 0){
                visit[ny][nx] = 1;
                q[rear].y = ny;
                q[rear].x = nx;
                rear++;
            }
        }
    }
}

void debug(){
    printf("\n");
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            printf("%d ", visit[i][j]);
        }
        printf("\n");
    }
}

int main(void){
    while(1){
        scanf("%d %d", &w, &h);
        if(w == 0 && h == 0) break;
        int ans = 0;
        init();
        for(int i = 1; i <= h; i++){
            for(int j = 1; j <= w; j++){
                scanf("%d", &arr[i][j]);
            }
        }
        for(int i = 1; i <= h; i++){
            for(int j = 1; j <= w; j++){
                if(arr[i][j] == 1 && visit[i][j] == 0){
                    ans += 1;
                    visit[i][j] = 1;
                    bfs(i,j);
                }
                //debug();
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}