#include <cstdio>

int X;
int init = 64;
int current = 0;
int ans = 0;

int main(void){
    scanf("%d", &X);

    while(current != X){
        while(current + init > X){
            init /= 2;
        }
        current += init;
        ans++;
    }
    printf("%d\n", ans);

    return 0;
}