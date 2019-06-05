#include <cstdio>

int prime[250000];

int main(void){
    int N, cnt;
    
    for(int i = 0; i < 250000; i++){
        prime[i] = i;
    }
    
    for(int i = 2; i < 250000; i++){
        if(prime[i] == 0){
            continue;
        }else{
            int j = i+i;
            while(j < 250000){
                if(prime[j] != 0){
                    prime[j] = 0;
                }
                j += i;
            }
        }
    }

    while(1){
        scanf("%d", &N);
        cnt = 0;
        if(N == 0) break;
        for(int i = N+1; i <= 2*N; i++){
            if(prime[i] != 0) cnt++;
        }
        printf("%d\n", cnt);
    }
    
    return 0;
}
