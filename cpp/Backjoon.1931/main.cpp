#include <cstdio>

#define MAX_L 100000

struct Time{
    int start;
    int end;
};

Time time_table[MAX_L];
Time buf[MAX_L];
int N;

void merge(Time *p, int len){
    if(len < 2 ) return;
    int i,j,k,mid;
    mid = len/2;
    merge(p, mid);
    merge(p+mid, len-mid);
    i = 0; j = mid; k = 0;
    while(i < mid && j < len){
        if(p[i].end < p[j].end){
            buf[k].start = p[i].start;
            buf[k].end = p[i].end;
            k++;i++;
        }else if(p[i].end > p[j].end){
            buf[k].start = p[j].start;
            buf[k].end = p[j].end;
            k++;j++;
        }else{
            if(p[i].start < p[j].start){
                buf[k].start = p[i].start;
                buf[k].end = p[i].end;
                k++;i++;
            }else{
                buf[k].start = p[j].start;
                buf[k].end = p[j].end;
                k++;j++;
            }
        }
    }
    while(i < mid){
        buf[k].start = p[i].start;
        buf[k].end = p[i].end;
        k++;i++;
    }
    while(j < len){
        buf[k].start = p[j].start;
        buf[k].end = p[j].end;
        k++;j++;
    }
    for(int i = 0; i < len; i++){
        p[i].start = buf[i].start;
        p[i].end = buf[i].end;
    }
}

int solve(Time* p, int len){
    int ret = 0;
    int end_time = 0;
    for(int i = 0; i < len; i++){
        if(p[i].start >= end_time){
            ret+=1;
            end_time = p[i].end;
        }
    }
    return ret;
}

int main(void){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d %d", &time_table[i].start, &time_table[i].end);
    }
    merge(time_table, N);
    printf("%d\n", solve(time_table, N));
    return 0;
}