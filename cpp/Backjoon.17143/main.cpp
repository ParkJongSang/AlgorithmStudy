#include <iostream>

#define MAXSIZE 102

using namespace std;

struct FISH {
    int x, y, s, z, dir, death;
}arr[MAXSIZE*MAXSIZE];

int map[MAXSIZE][MAXSIZE];
int dx[] = { 0, 0, 0, 1, -1 };
int dy[] = { 0, -1, 1, 0, 0 };
int R, C, M, dab;

int main(void) {
    cin >> R >> C >> M;

    for (int i = 1; i <= M; i++) {
        cin >> arr[i].y >> arr[i].x >> arr[i].s >> arr[i].dir >> arr[i].z;
        arr[i].y -= 1;
        arr[i].x -= 1;
        map[arr[i].y][arr[i].x] = i;
    }

    for (int t = 0; t < C; t++) {
        for (int y = 0; y < R; y++) { // 물고기 잡기
            if (map[y][t]) {
                arr[map[y][t]].death = 1;
                dab += arr[map[y][t]].z;
                map[y][t] = 0;
                break;
            }
        }

        int tmp[MAXSIZE][MAXSIZE] = { 0 };
        for (int i = 1; i <= M; i++) {
            if (arr[i].death) continue; // 죽은 물고기 continue;
            int ix = arr[i].x, iy = arr[i].y, s = arr[i].s, idir = arr[i].dir;
            int nx, ny;
            while (1) {
                nx = ix + s * dx[idir]; 
                ny = iy + s * dy[idir];
                if (nx < C && ny < R && ny >= 0 && nx >= 0)
                    break;
                if (idir == 1 && ny < 0) { 
                    s -= iy; 
                    iy = 0; 
                    idir = 2;  
                }else if (idir == 2 && ny >= R) {
                    s -= R - 1 - iy; 
                    iy = R - 1; 
                    idir = 1;   
                }else if (idir == 3 && nx >= C) { 
                    s -= C - 1 - ix; 
                    ix = C - 1; 
                    idir = 4; 
                }else if (idir == 4 && nx < 0) { 
                    s -= ix; 
                    ix = 0; 
                    idir = 3;  
                }
            }
            if (tmp[ny][nx]) {
                if (arr[tmp[ny][nx]].z < arr[i].z) { 
                    arr[tmp[ny][nx]].death = 1;
                    tmp[ny][nx] = i; 
                }else{
                    arr[i].death = 1;
                }
            }else {
                tmp[ny][nx] = i;
            }
            arr[i].x = nx; 
            arr[i].y = ny; 
            arr[i].dir = idir;
            
        }
        for (int y = 0; y < R; y++)
            for (int x = 0; x < C; x++)
                map[y][x] = tmp[y][x];

    }
    cout << dab << endl;
    return 0;
}
