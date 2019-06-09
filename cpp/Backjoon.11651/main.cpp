#include <cstdio>
#define MAX_L 100000

struct Point{
    int x;
    int y;
};

Point ms[MAX_L], buf[MAX_L];

void merge(Point *p, int len){
    if(len < 2) return;
    int i,j,k,mid;
    mid = (len/2);
    i = 0; j = mid; k = 0;

    merge(p, mid);
    merge(p+mid, len-mid);

    while(i < mid && j < len){
        if(p[i].y < p[j].y){
            buf[k].y = p[i].y;
            buf[k].x = p[i].x;
            k++;i++;
        }else if(p[i].y > p[j].y){
            buf[k].y = p[j].y;
            buf[k].x = p[j].x;
            k++; j++;
        }else{
            if(p[i].x < p[j].x){
                buf[k].y = p[i].y;
                buf[k].x = p[i].x;
                k++;i++;
            }else{
                buf[k].y = p[j].y;
                buf[k].x = p[j].x;
                k++; j++;
            }
        }
    }

    while(i < mid){
        buf[k].y = p[i].y;
        buf[k].x = p[i].x;
        k++;i++;
    }
    while(j < len){
        buf[k].y = p[j].y;
        buf[k].x = p[j].x;
        k++; j++;
    }

    for(int i = 0; i < len; i++){
        p[i].y = buf[i].y;
        p[i].x = buf[i].x;
    }
}

int main(void){
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &ms[i].x, &ms[i].y);
    }
    merge(ms, n);
    for(int i = 0; i < n; i++){
        printf("%d %d\n", ms[i].x, ms[i].y);
    }
    return 0;
}