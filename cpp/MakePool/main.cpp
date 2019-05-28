#include <iostream>
#include <queue>

using namespace std;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

struct point{
    int y;
    int x;
};

int N, M;
int map[60][60];
int visit[60][60];

int ans = 0;

void init_visit(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            visit[i][j] = 0;
        }
    }
}

bool is_inside(int y, int x){
    if(y >= 0 && y < N && x >= 0 && x < M){
        return true;
    }
    return false;
}

void bfs(int y, int x, int height){
    queue<point> q;
    vector<point> v;

    point temp = {y, x};
    q.push(temp);
    v.push_back(temp);

    visit[y][x] = 1;

    int min_height = 99999999;

    while(!q.empty()){
        int cy = q.front().y;
        int cx = q.front().x;
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(nx >= 1 && ny >= 1 && nx < (M - 1) && ny < (N - 1)){
                if(map[ny][nx] == height && visit[ny][nx] == 0){
                    visit[ny][nx] = 1;
                    temp = {ny, nx};
                    q.push(temp);
                    v.push_back(temp);
                }
            }
        }
    }

    for(int i = 0; i < v.size(); i++){
        int cx = v[i].x;
		int cy = v[i].y;   
        for(int i = 0; i < 4; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(is_inside(ny, nx) && visit[ny][nx] == 0){
                min_height = min(min_height, map[ny][nx]);
            }
        }
    }

    if(min_height < 999999 && min_height > height){
        for(int i = 0; i < v.size(); i++){
            ans += min_height - map[v[i].y][v[i].x];
            map[v[i].y][v[i].x] = min_height;
        }
    }
    
    return;
}

int main(void){
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            char temp;
            cin >> temp;
            map[i][j] = temp-'0';
        }
    }

    for(int k = 1; k < 9; k++){
        init_visit();
        for(int i = 1; i < N-1; i++){
            for(int j = 1; j < M-1; j++){
                if(k == map[i][j] && visit[i][j] == 0){
                    bfs(i, j , k);
                }
            }
        }
    }

    cout << ans;
    
    return 0;
}