#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ans = 987654321;
char board[51][51];
int Y, X;
int T;
vector<int> v;

int check(){
    int ret = 0;
    for(int i = 0; i < v[0]; i++){
        for(int j = 0; j < X; j++){
            if(board[i][j] != 'W') ret++;
        }
    }
    for(int i = v[0]; i < v[1]; i++){
        for(int j = 0; j < X; j++){
            if(board[i][j] != 'B') ret++;
        }
    }
    for(int i = v[1]; i < v[2]; i++){
        for(int j = 0; j < X; j++){
            if(board[i][j] != 'R') ret++;
        }
    }
    return ret;
}

void dfs(int depth, int sum){
    if(depth == 3){
        if(sum != Y){
            return;
        }else{
            // for(int i =0 ; i < v.size(); i++){
            //     cout << v[i] << " ";
            // }
            // cout << endl;
            ans = min(ans, check());
            return;
        }
    }

    for(int i = 1; i < Y; i++){
        v.push_back(sum+i);
        dfs(depth+1, sum+i);
        v.pop_back();
    }
}

void init(){
    ans = 987654321;
    X = 0;
    Y = 0;
    v.clear();
    for(int i = 0; i < Y; i++){
        for(int j = 0; j < X; j++){
            board[i][j] = 0;
        }
    }
}

int main(void){
    cin >> T;
    int tc = 1;
    while(T--){
        init();

        cin >> Y >> X;
        for(int i = 0; i < Y; i++){
            cin >> board[i];
            // cout << board[i] <<"\n";
        }

        
        dfs(0, 0);
        cout <<"#" <<tc++<<" "<<ans<<"\n";
    }
    return 0;
}