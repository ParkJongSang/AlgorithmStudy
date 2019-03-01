#include <iostream>

using namespace std;

const int order[4][2] = {
    {0,0}, {0, 1},
    {1,0}, {1, 1}
};


int size;
int sy = 1;
int sx = 1;
int r, c;
int N;
int visit_order = 0;
int ans = 0;

void solve(int y, int x, int size){
    if(size < 2){
        return;
    }
    if(size == 2){
        for(int i = 0; i < 4; i++){
            int cy = y + order[i][0];
            int cx = x + order[i][1];
            if(cx == c && cy == r){
                ans = visit_order++;
                return;
            }
            //cout << cx << " " << cy << endl;
            visit_order += 1;
        }
        return;
    }
    solve(y, x, size/2);
    solve(y, (x+size/2), size/2);
    solve((y+size/2), x, size/2);
    solve((y+size/2), (x+size/2), size/2);
    return;
}

int main(void){
    cin >> N >> r >> c;
    int size = 1;
    for(int i = 0; i < N; i++){
        size *= 2;
    }
    //cout << size << endl;
    solve(0, 0, size);
    cout << ans << "\n";
    return 0;
}