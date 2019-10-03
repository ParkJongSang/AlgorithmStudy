#include <cstdio>
#include <queue>

using namespace std;

int dy[4] = {0,0,1,-1};
int dx[4] = {-1,1,0,0};

struct info{
    int y;
    int x;
};

info virus[10];
int dist[50][50] = {0, };
int board[50][50];
int ans = -1;
int N, M;
int virusCnt = 0;
vector<info> selectedVirus;

bool IsInside(int y, int x){
    if(y >= 0 && y < N && x >= 0 && x < N){
        return true;
    }
    return false;
}

int bfs(){
    int ret = 0;
    queue<info> q;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            dist[i][j] = 5000;
        }
    }

    for(int i = 0; i < selectedVirus.size(); i++){
        dist[selectedVirus[i].y][selectedVirus[i].x] = 0;
        q.push(selectedVirus[i]);
    }

    while(!q.empty()){
        int cy = q.front().y;
        int cx = q.front().x;
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(IsInside(ny, nx) && dist[ny][nx] > dist[cy][cx]+1 && board[ny][nx] != 1){        
                dist[ny][nx] = dist[cy][cx] + 1;
                info temp = {ny, nx};
                q.push(temp);
                if(board[ny][nx] != 2) ret = max(ret, dist[ny][nx]);
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(board[i][j] == 0 && dist[i][j] == 5000){
                return -1;
            }
        }
    }

    return ret;
}

void selectVirus(int idx, int depth){
    if(depth >= M){
        int ret = bfs();
        if(ans == -1 && ret != -1){
            ans = ret;
        }
        if(ret == -1){
            return;
        }
        ans = min(ans, ret);
        return;
    }
    for(int i = idx; i < virusCnt; i++){
        selectedVirus.push_back(virus[i]);
        selectVirus(i+1, depth+1);
        selectedVirus.pop_back();
    }
}

int main(void){
    scanf("%d %d", &N, &M);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &board[i][j]);
            if(board[i][j] == 2){
                virus[virusCnt].y = i;
                virus[virusCnt].x = j;
                virusCnt++;
            }
        }
    }
    selectVirus(0, 0);
    printf("%d\n", ans);
    return 0;
}