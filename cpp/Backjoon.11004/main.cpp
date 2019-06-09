#include <cstdio>
#define MAX_SIZE 5000000

int ms[MAX_SIZE], buf[MAX_SIZE];
int n, k;
void merge(int *p, int len){
    if(len < 2) return;
    int i,j,k,mid;
    mid = (len/2);
    i = 0, j = mid, k = 0;

    merge(p, mid);
    merge(p+mid, len-mid);

    while(i < mid && j < len){
        if(p[i] < p[j]) buf[k++] = p[i++];
        else buf[k++] = p[j++];
    }
    while(i < mid) buf[k++] = p[i++];
    while(j < len) buf[k++] = p[j++];
    for(int i = 0; i < len; i++) p[i] = buf[i];
}

int main(void){
    int n, k; scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d", &ms[i]);
    }
    merge(ms, n);
    printf("%d\n", ms[k-1]);
    return 0;
}