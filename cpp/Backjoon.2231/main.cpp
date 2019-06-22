#include <cstdio>


int main(void){
    int ans = -1;
    int N; scanf("%d", &N);
    for(int i = 1; i <= 1000000; i++){
        int tmp = i;
        int M = tmp;
        while(tmp != 0){
            M += tmp % 10;
            tmp /= 10;
        }
        if(M == N){
            ans = i;
            break;
        }
    }
    if(ans == -1){
        printf("0\n");
    }else{
        printf("%d\n", ans);
    }
    return 0;
}