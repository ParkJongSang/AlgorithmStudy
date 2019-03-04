#include <stdio.h>

int N, W, H;
int data[15][12];
int map[15][12];
int ans;

void init(){
    ans = 987654321;
}

void block_init(){
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            map[i][j] = data[i][j];
        }
    }
}

int bomb_1(){
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(map[i][j] > 10){
                int d = map[i][j] - 10;
                map[i][j] = 0;

                int sx = j - d + 1;
                int ex = j + d - 1;
                if(sx < 0) sx = 0;
                if(ex >= W) ex = W - 1;

                int flag = 0;

                for(int x = sx; x <= ex; x++){
                    if(map[i][x] == 1) map[i][x] = 0;
                    else if(map[i][x] > 1 && map[i][x] < 10) {
                        map[i][x] += 10;
                        flag = 1;
                    }
                }

                int sy = i - d + 1;
                int ey = i + d - 1;
                if(sy < 0 ) sy = 0;
                if(ey >= H) ey = H - 1;

                for(int y = sy; y <= ey; y++){
                    if(map[y][j] == 1) map[y][j] = 0;
                    else if(map[y][j] > 1 && map[y][j] < 10){
                        map[y][j] += 10;
                        flag = 1;
                    }
                }
                if(flag == 1) return 1;
            }
        }
    }
    return 0;
}

void bomb(int x){
    for(int y = 0; y < H; y++){
        if(map[y][x] == 1){
            map[y][x] = 0; return;
        }else if(map[y][x] > 1){
            map[y][x] += 10;
            break;
        }
    }
    int flag = 1;
    while(flag) flag = bomb_1();
}

void down(){
    for(int k = 0; k < W; k++){
        for(int i = H-1; i >= 0; i--){
            if(map[i][k] == 0){
                for(int y = i-1; y >= 0; y--){
                    if(map[y][k] != 0){
                        map[i][k] = map[y][k];
                        map[y][k] = 0;
                        break;
                    }
                }
            }
        }
    }
}

void block_check() {
    int ret = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (map[i][j] > 0) ret++;
        }
    }
    if(ans > ret) ans = ret;
}

void solve(){
    int B[4];
    for(B[0] = 0; B[0] < W; B[0]++){
        for(B[1] = 0; B[1] < W; B[1]++){
            for(B[2] = 0; B[2] < W; B[2]++){
                for(B[3] = 0; B[3] < W; B[3]++){
                    block_init();

                    for(int i = 0; i < N; i++){
                        bomb(B[i]);
                        down();
                    }

                    block_check();

                    if(ans == 0){
                        return;
                    }
                    if(N < 4) break;
                }
                if(N < 3) break;
            }
            if(N < 2) break;
        }
    }
}

int main(void){
    int tc = 0;
    scanf("%d", &tc);

    for(int t = 1; t <= tc; t++){
        scanf("%d %d %d", &N, &W, &H);
        for(int y = 0; y < H; y++){
            for(int x = 0; x < W; x++){
                scanf("%d", &data[y][x]);
            }
        }
        init();
        solve();

        printf("#%d %d\n", t, ans);
    }

    return 0;
}