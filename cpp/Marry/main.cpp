#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N, M;

int visit[10001];
vector<int> fri_list[10001];

void debug(){
    for(int i = 0; i < fri_list[1].size(); i++){
        cout << fri_list[1][i] << " ";
    }cout << "\n";
}

void init(){
    for(int i = 0; i <= N; i++){
        fri_list[i].resize(N+1);
        visit[i] = 0;
    }
}

void solve(){
    queue<int> q;

    for(int i = 0; i < fri_list[1].size(); i++){
        q.push(fri_list[1][i]);
        visit[fri_list[1][i]] = 1;
    }

    visit[1] = 1;

    while(!q.empty()){
        //cout << q.front() << endl;
        int poll = q.front();
        q.pop();
        visit[poll] = 1;
        //debug();
        for(int i = 0; i < fri_list[poll].size(); i++){
            if(!visit[fri_list[poll][i]]){
                visit[fri_list[poll][i]] = 1;
                fri_list[1].push_back(fri_list[poll][i]);
            }
        }
    }
}

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;
    cin >> M;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        fri_list[a].push_back(b);
        fri_list[b].push_back(a);
    }
    solve();
    //debug();
    cout << fri_list[1].size(); 

}