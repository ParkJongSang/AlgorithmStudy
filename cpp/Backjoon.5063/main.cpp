#include <cstdio>

int main(void){
    int n; scanf("%d", &n);
    while(n--){
        int r, e, c; scanf("%d %d %d", &r, &e, &c);
        int ret = r - (e - c);
        if(ret > 0){
            printf("do not advertise\n");
        }else if(ret == 0){
            printf("does not matter\n");
        }else{
            printf("advertise\n");
        }
    }
    return 0;
}