#include <cstdio>

int main(void){
    int total; scanf("%d", &total);
    for(int i = 0; i < 9; i++){
        int tmp; scanf("%d", &tmp);
        total -= tmp;
    }
    printf("%d\n", total);
    return 0;
}