#include <iostream>
#include <queue>

using namespace std;

const int dy[4] = {1,-1,0,0};
const int dx[4] = {0,0,1,-1};

int arr[8][8];
int visit[8][8];
int N, K;
int high_y[5];
int high_x[5];
int high_size;
int ans;

void init(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            arr[i][j] = 0;
        }
    }
    for(int i = 0; i < 5; i++){
        high_x[i] = -1;
        high_y[i] = -1;
    }
    high_size = 0;
    ans = 0;
}

bool is_inside(int y, int x){
    if(y >= 0 && y < N && x >= 0 && x < N){
        return true;
    }
    return false;
}

int find_highest(){
    int ret = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
           ret = max(ret, arr[i][j]);
        }
    }
    return ret;
}

void decide_start_vector(int high){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(arr[i][j] == high){
                high_y[high_size] = i;
                high_x[high_size] = j;
                high_size++;
            }
        }
    }
}

void dfs(int y, int x, int dist){

    ans = max(dist, ans);

    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];    
        if(is_inside(ny, nx) && visit[ny][nx] != 1 && arr[y][x] > arr[ny][nx]){
            visit[ny][nx] = 1;
            dfs(ny, nx, dist+1);
            visit[ny][nx] = 0;
        }
    }
}

void solve(){
    for(int k = 0; k < high_size; k++){
        int start_y = high_y[k];
        int start_x = high_x[k];
        visit[start_y][start_x] = 1;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(start_y == i && start_x == j){
                    continue;
                }
                for(int w = 1; w <= K; w++){
                    arr[i][j] = arr[i][j] - w;
                    dfs(start_y, start_x, 1);
                    arr[i][j] = arr[i][j] + w;
                }
            }
        }
         visit[start_y][start_x] = 0;
    }
}

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int tc = 0;
    cin >> tc;
    for(int t = 1; t <= tc; t++){
        init();
        cin >> N >> K;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> arr[i][j];
            }
        }

        int high = find_highest();

        decide_start_vector(high);

        solve();

        cout <<"#"<< t <<" "<< ans << endl;
    }
    return 0;
}