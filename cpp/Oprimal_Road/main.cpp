#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

int visit[10];
int work_x;
int work_y;
int home_x;
int home_y;
int vertex_x[10];
int vertex_y[10];
int num_of_vertex;
int ans = numeric_limits<int>::max();

void reset(){
    for(int i = 0; i < 10; i++){
        visit[i] = 0;
        vertex_x[i] = 0;
        vertex_y[i] = 0;
    }
    ans = numeric_limits<int>::max();
};

int calc_dist(int x1, int y1, int x2, int y2){
    return abs(x1-x2) + abs(y1-y2);
}

void dfs(int dist, int x, int y, int depth){
    int new_dist;
    if(depth >= num_of_vertex-1){
        new_dist = dist + calc_dist(x, y, home_x, home_y);
        ans = min(ans, new_dist);
        return;
    }
    for(int i = 0; i < num_of_vertex; i++){
        if(visit[i] == 0){
            visit[i] = 1;
            new_dist = dist + calc_dist(x, y, vertex_x[i], vertex_y[i]);
            dfs(new_dist, vertex_x[i], vertex_y[i], depth+1);
            visit[i] = 0;
        }
    }
}

void solve(){
    for(int i = 0; i < num_of_vertex; i++){
        if(visit[i] == 0){
            visit[i] = 1;
            int dist = calc_dist(work_x, work_y, vertex_x[i], vertex_y[i]);
            dfs(dist,  vertex_x[i], vertex_y[i], 0);
            visit[i] = 0;
        }
    }
}

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int tc = 0;
    cin >> tc;

    for(int t = 1; t <= tc; t++){
        cin >> num_of_vertex;
        cin >> work_x >> work_y >> home_x >> home_y;
        for(int i = 0; i < num_of_vertex; i++){
            int x, y;
            cin >> x >> y;
            vertex_x[i] = x;
            vertex_y[i] = y;
        }

        solve();
        cout << "#" << t << " " << ans << "\n";
        reset();
    }
    
    return 0;
}