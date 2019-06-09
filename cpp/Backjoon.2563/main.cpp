#include <cstdio>

int board[101][101];

int main(void){
    int n; 
    scanf("%d", &n);
    int ans = 0;
    for(int i = 0; i < n; i++){
        int a, b; 
        scanf("%d %d", &a, &b);
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){
                if(!board[a+j][b+k]){
                    board[a+j][b+k] = 1;
                    ++ans;
                }
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}