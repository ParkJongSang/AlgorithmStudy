#include <iostream>

using namespace std;

int N;
int map[101][101] = {0, };
const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {1, 0, -1, 0};

int main(void){
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;

    for(int i = 0; i < N; i++){
        int curve_size = 0;
        int curve[1024] = {0, };

        int x, y, d, g;
        cin >> x >> y >> d >> g;

        curve[curve_size++] = d;
        map[y][x] = 1;

        for(int j = 0; j < g; j++){
            for(int k = curve_size - 1; k >= 0; k--){
                curve[curve_size++] = (curve[k] + 1) % 4;
            }
        }

        for(int j = 0; j < curve_size; j++){
            y += dy[curve[j]];
            x += dx[curve[j]];
            if(y < 0 || y >= 101 || x < 0 || x >= 101){
                continue;
            }
            map[y][x] = 1;
        }
       
    }

    int ret = 0;

    for(int j = 0; j < 101; j++){
        for(int k = 0; k < 101; k++){
            if(map[j][k] && map[j+1][k] && map[j][k+1] && map[j+1][k+1]){
                 ret += 1;
            }
        }
    }

    cout << ret;

    return 0;
}