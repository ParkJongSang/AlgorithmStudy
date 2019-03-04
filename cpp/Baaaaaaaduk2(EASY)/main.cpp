#include <iostream>
#include <queue>


using namespace std;

const int dx[4] = {-1,1,0,0};
const int dy[4] = {0,0,-1,1};

int N, M;
int board[20][20];
int visit[20][20];
int ans = 0;

struct point{
    int y;
    int x;
};

vector<point> two;
vector<point> reset;

void reset_visit(){
    for(int i = 0; i < reset.size(); i++){
        int cy = reset[i].y;
        int cx = reset[i].x;
        visit[cy][cx] = 0;
    }
    while(!reset.empty()){
        reset.pop_back();
    }
}

bool is_inside(int y, int x){
    if(y >= 0 && y < N && x >= 0 && x < M){
        return true;
    }
    return false;
}

int cnt_bfs(point start, int visit[20][20]){
    int ret = 0;
    bool flag = false;
    queue<point> q;
    q.push(start);
    reset.push_back(start);
    visit[start.y][start.x] = 1;
    ret += 1;

    while(!q.empty()){
        int cy = q.front().y;
        int cx = q.front().x;
        q.pop();

        for(int i = 0; i < 4; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(is_inside(ny, nx) && board[ny][nx] == 0){
                flag = true;
            }
            if(is_inside(ny, nx) && visit[ny][nx] == 0 && board[ny][nx] == 2){
                ret += 1;
                visit[ny][nx] = 1;
                reset.push_back({ny, nx});
                point temp = {ny, nx};
                q.push(temp);
            }
        }
    }
    if(flag){
        return 0;
    }
    return ret;
}

int cnt_func(){
    int ret = 0;
    reset_visit();
    for(int i = 0; i < two.size(); i++){
        int cy = two[i].y;
        int cx = two[i].x;
        if(visit[cy][cx] == 0){
            ret += cnt_bfs({cy, cx}, visit);
        }
    }
    return ret;
}


void select_zero(int cy, int cx, int cnt){
    if(cnt == 2){
        ans = max(ans, cnt_func());
        return;
    }
    for(int y = cy; y < N; y++){
        for(int x = cx; x < M; x++){
            if(board[y][x] == 0){
                board[y][x] = 1;
                select_zero(y, x+1, cnt+1);
                board[y][x] = 0;
            }
        }
        cx = 0;
    }
    return;
}

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> M;

    for(int y = 0; y < N; y++){
        for(int x = 0; x < M; x++){
            cin >> board[y][x];
            if(board[y][x] == 2){
                two.push_back({y,x});
            }
        }
    }

    for(int y = 0; y < N; y++){
        for(int x = 0; x < M; x++){
            if(board[y][x] == 0){
                select_zero(y, x, 0);
            }
        }
    }

    cout << ans << endl;
    return 0;
}