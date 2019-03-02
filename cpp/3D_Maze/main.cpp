#include <iostream>
#include <queue>

using namespace std;

const int dx[6] = {-1,1,0,0,0,0};
const int dy[6] = {0,0,-1,1,0,0};
const int dz[6] = {0,0,0,0,-1,1};
const int start_point[4][3] = {{0,0,0}, {0,0,4}, {0,4,0}, {0,4,4}};
const int end_point[4][3] = {{4,4,4}, {4,4,0}, {4,0,4}, {4,0,0}};

int init_maze[5][5][5];
int floor_visit[5];
int heap_maze[5][5][5];
int new_maze[5][5][5];
int visit[5][5][5];
int dist[5][5][5];
int allone[5] = {1,1,1,1,1};
int ans = 999999;

struct point{
    int z;
    int y;
    int x;
};

void debug(){
    cout << "==============" << endl;
    for(int k = 0; k < 5; k++){
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                cout << new_maze[k][i][j] << "\t";
            }cout << endl;
        }cout << endl;
    }cout << endl;
    cout << endl;
}

void reset_visit_dist(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            for(int k = 0; k < 5; k++){
                visit[i][j][k] = 0;
                dist[i][j][k] = 0;
            }
        }
    }
}

bool is_inside(int z, int y, int x){
    if((z >= 0 && z < 5) && (y >= 0 && y < 5) && (x >= 0 && x < 5)){
        return true;
    }
    return false;
}

void bfs(){
    for(int i = 0; i < 4; i++){
        reset_visit_dist();
        queue<point> q;
        int z = start_point[i][0], y = start_point[i][1], x = start_point[i][2];
        int ez = end_point[i][0], ey = end_point[i][1], ex = end_point[i][2];

        //debug();

        if(new_maze[z][y][x] == 0 || new_maze[ez][ey][ex] == 0){
            continue;
        }

        point sp = {z, y, x};
        q.push(sp);
        dist[z][y][x] = 0;
        visit[z][y][x] = 1;
        while(!q.empty()){
            int cz = q.front().z;
            int cy = q.front().y;
            int cx = q.front().x;
            q.pop();
            for(int i = 0; i < 6; i++){
                int nz = cz + dz[i];
                int ny = cy + dy[i];
                int nx = cx + dx[i];
                if(is_inside(nz, ny, nx) && visit[nz][ny][nx] == 0 && new_maze[nz][ny][nx] == 1){
                    visit[nz][ny][nx] = 1;
                    dist[nz][ny][nx] = dist[cz][cy][cx] + 1;
                    point temp = {nz, ny, nx};
                    q.push(temp);
                }
            }
        }
        //debug();
        if(dist[ez][ey][ex] != 0){
            ans = min(ans, dist[ez][ey][ex]);
        }

    }
}

void rotate(int floor, int rotate){
    int cur_rotate = 0;


    for(int y = 0; y < 5; y++){
        for(int x = 0; x < 5; x++){
            new_maze[floor][y][x] = heap_maze[floor][y][x];
        }
    }

    while(cur_rotate < rotate){
        int ret[5][5] = {0, };
        for(int y = 0; y < 5; y++){
            for(int x = 0; x < 5; x++){
                ret[x][4-y] = new_maze[floor][y][x];
            }
        }

        for(int y = 0; y < 5; y++){
            for(int x = 0; x < 5; x++){
                new_maze[floor][y][x] = ret[y][x];
            }
        }
        cur_rotate += 1;
    }
    //debug();
}

void rotate_floor(){
    bool flag = true;
    for(int i = 0; i < 5; i++){
        if(allone[i] == 0){
            flag = false;
            break;
        }
    }
    if(flag == true){
        for(int z = 0; z < 5; z++){
            for(int y = 0; y < 5; y++){
                for(int x = 0; x < 5; x++){
                    new_maze[z][y][x] = heap_maze[z][y][x];
                }
            }
        }
        bfs();
        return;
    }
    for(int a = 0; a < 4; a++){
        for(int b = 0; b < 4; b++){
            for(int c = 0; c < 4; c++){
                for(int d = 0; d < 4; d++){
                    for(int e = 0; e < 4; e++) {
                        rotate(0, a);
                        rotate(1, b);
                        rotate(2, c);
                        rotate(3, d);
                        rotate(4, e);
                        bfs();
                    }
                }
            }
        }
    }
}

void make_floor(int depth){
    if(depth > 4){
        rotate_floor();
        return;
    }
    for(int i = 0; i < 5; i++){
        if(floor_visit[i] == 0){
            floor_visit[i] = 1;
            for(int y = 0; y < 5; y++){
                for(int x = 0; x < 5; x++){
                    heap_maze[depth][y][x] = init_maze[i][y][x];
                }
            }
            make_floor(depth+1);
            floor_visit[i] = 0;
        }
    }
    return;
}


int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    for(int z = 0; z < 5; z++){
        for(int y = 0; y < 5; y++){
            for(int x = 0; x < 5; x++){
                cin >> init_maze[z][y][x];
                if(init_maze[z][y][x] == 0){
                    allone[z] = 0;
                }
            }
        }
    }
    //debug();
    make_floor(0);
    if(ans == 999999){
        cout << -1 << "\n";
    }else{
        cout << ans << "\n";
    }
    return 0;
}