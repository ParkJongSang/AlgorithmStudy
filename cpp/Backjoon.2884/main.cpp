#include <cstdio>

int main(void){
    int h, m; scanf("%d %d", &h, &m);
    int re_m = m - 45;
    if(re_m < 0){
        re_m += 60;
        h--;
    }
    if(h < 0){
        h = 23;
    }
    printf("%d %d\n", h, re_m);
    return 0;
}