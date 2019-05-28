#include <stdio.h>
#include <queue>
#include <memory.h>
#include <algorithm>

using namespace std;

const int dy[4] = {0,0,-1,1};
const int dx[4] = {1,-1,0,0};

int N, M;
int map[20][20];
int price[22];
int range[22];
int cnt = 0;
int ans = -1;
int visit[20][20];

struct point{
    int y;
    int x;
};
void reset(){
    for(int i = 0; i < N; i++){
         for(int j = 0; j < N; j++){
            visit[i][j] = 0;
        }
    }
    for(int i = 0; i <= N+1; i++){
        range[i] = 0;
    }
}
bool is_inside(int y, int x){
    if(y >= 0 && y < N && x >= 0 && x < N){
        return true;
    }
    return false;
}

void solve(int y, int x){
    queue<point> q;

    q.push({y, x});

    visit[y][x] = 1;

    while(!q.empty()){
        int cy = q.front().y;
        int cx = q.front().x;
        q.pop();

        if(visit[cy][cx] > N+1)return;
        if(map[cy][cx])range[visit[cy][cx]] += 1;

        for(int i = 0; i < 4; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(is_inside(ny, nx) && !visit[ny][nx]){
                visit[ny][nx] = visit[cy][cx] + 1;
                q.push({ny,nx});
            }
        }
    }
}

int get_ans(){
    int ret = 0;
    int sum = 0;
    for(int i = 1; i <= N+1; i++){
        sum += range[i];
        if(sum * M - price[i] >= 0){
            ret = sum;
        }
    }
    return ret;
}

int main(void){
    price[1] = 1;
    for(int i = 2; i < 22; i++){
        price[i] = price[i-1] + ((i-1) * 4);
    }

    int test_case;
    scanf("%d", &test_case);

    for(int tc = 1; tc <= test_case; tc++){
        ans = -1;
        scanf("%d %d", &N, &M);

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                scanf("%d", &map[i][j]);
            }
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                solve(i,j);
                ans = max(ans, get_ans());
                memset(range, 0, sizeof(range));
                memset(visit, 0, sizeof(visit));
            }
        }
        
        printf("#%d %d\n", tc, ans);
    }
    return 0;
}