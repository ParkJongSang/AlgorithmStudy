#include <stdio.h>

int N;
int cache[21];

int main(void){
    scanf("%d", &N);
    cache[0] = 0; cache[1] = 1;
    for(int i = 2; i < 21; i++){
        cache[i] = cache[i-1] + cache[i-2];
    }
    printf("%d\n", cache[N]);
    return 0;
}