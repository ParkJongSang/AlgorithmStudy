#include <iostream>
#include <vector>

using namespace std;

const int dy[4] = {-1,1,1,-1};
const int dx[4] = {1,1,-1,-1};

int visit[20][20];
int arr[20][20];
int N;
int ans;
int eat[101];

void init(){
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            visit[i][j] = 0;
            arr[i][j] = 0;
        }
    }
    ans = -1;
    for(int i = 0; i < 101; i++){
        eat[i] = 0;
    }
}

bool is_inside(int y, int x){
    if(y >= 0 && y < N  && x >= 0 && x < N){
        return true;
    }
    return false;
}

void solve(int y, int x, int dir, int depth){
    if(depth == )
}

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int tc  = 0;
    cin >> tc;
    for(int t = 1; t <= tc; t++){
        cin >> N;

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> arr[i][j];
            }
        }

    }

    return 0;
}