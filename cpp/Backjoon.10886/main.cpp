#include <cstdio>

int N;
int y = 0, n = 0;

int main(void){
    scanf("%d", &N);
    while(N--){
        int tmp; scanf("%d", &tmp);
        if(tmp) y++;
        else n++;
    }
    if(y > n){
        printf("Junhee is cute!");
    }else{
        printf("Junhee is not cute!");
    }
    return 0;
}
