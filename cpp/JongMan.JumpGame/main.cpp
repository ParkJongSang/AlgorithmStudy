#include <cstdio>

int n, board[100][100];
int cache[100][100];

int jump(int y, int x){
    if(y >= n || x >= n) return 0;
    if(y == n-1 && x == n-1) return 1;
    int &ret = cache[y][x];
    if(ret != -1) return ret;
    int jumpSize = board[y][x];
    return ret = (jump(y+jumpSize, x) || jump(y, x+jumpSize));
}

int main(void){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &board[i][j]);
            cache[i][j] = -1;
        }
    }
}