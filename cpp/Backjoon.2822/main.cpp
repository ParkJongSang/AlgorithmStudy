#include <cstdio>

struct Problem{
    int idx;
    int score;
};

Problem arr[8], buf[8];

void merge_pro(Problem *p, int len){
    if(len < 2) return;
    int i,j,k,mid;
    mid = len/2;
    i = 0; j = mid; k = 0;

    merge_pro(p, mid);
    merge_pro(p+mid, len-mid);

    while(i < mid && j < len){
        if(p[i].score > p[j].score) {
            buf[k].score = p[i].score;
            buf[k].idx = p[i].idx;
            k++; i++;
        }else{
            buf[k].score = p[j].score;
            buf[k].idx = p[j].idx;
            k++; j++;
        }
    }
    while(i < mid) {
        buf[k].score = p[i].score;
        buf[k].idx = p[i].idx;
        k++; i++;
    }
    while(j < len) {
        buf[k].score = p[j].score;
        buf[k].idx = p[j].idx;
        k++; j++;
    }
    
    for(int i = 0; i < len; i++){
        p[i].idx = buf[i].idx;
        p[i].score = buf[i].score;
    }
}

void merge_idx(int *p, int len){
    if(len < 2) return;
    int i,j,k,mid;
    mid = len/2;
    i = 0; j = mid; k = 0;

    merge_idx(p, mid);
    merge_idx(p+mid, len-mid);

    while(i < mid && j < len){
        if(p[i] < p[j]) {
            buf[k].idx = p[i];
            k++; i++;
        }else{
            buf[k].idx = p[j];
            k++; j++;
        }
    }
    while(i < mid) {
        buf[k].idx = p[i];
        k++; i++;
    }
    while(j < len) {
        buf[k].idx = p[j];
        k++; j++;
    }
    
    for(int i = 0; i < len; i++){
        p[i] = buf[i].idx;
    }
}

int main(void){
    int sum = 0;
    int ret[5] = {0, };
    for(int i = 0; i < 8; i++){
        arr[i].idx = i+1;
        scanf("%d", &arr[i].score);
    }
    merge_pro(arr, 8);
    for(int i = 0; i < 5; i++){
        sum += arr[i].score;
        ret[i] = arr[i].idx;
    }
    printf("%d\n", sum);
    merge_idx(ret, 5);
    for(int i = 0; i < 5; i++){
        printf("%d ", ret[i]);
    }
    printf("\n");
    return 0;
}