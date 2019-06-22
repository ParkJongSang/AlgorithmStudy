#include <cstdio>
#define MAX_L 500000

int number_card[MAX_L];
int query[MAX_L];
int buffer[MAX_L];
int N, M;

void merge(int *p, int len){
    if(len < 2) return;
    int i,j,k,mid;
    
    mid = len / 2;
    merge(p, mid);
    merge(p+mid, len-mid);

    i = 0; j = mid; k = 0;
    
    while(i < mid && j < len){
        if(p[i] < p[j]) buffer[k++] = p[i++];
        else buffer[k++] = p[j++];
    }
    while(i < mid){
        buffer[k++] = p[i++];
    }
    while(j < len){
        buffer[k++] = p[j++];
    }
    for(int i = 0; i < len; i++){
        p[i] = buffer[i];
    }
}

int lower_search(int key){
    int start = 0, end = N-1;
    while(start <= end){
        int mid = (start+end)/2;
        if(number_card[mid] < key){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    return end;
}

int upper_search(int key){
    int start = 0, end = N-1;
    while(start <= end){
        int mid = (start+end)/2;
        if(number_card[mid] <= key){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    return end;
}

int main(void){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &number_card[i]);
    }
    scanf("%d", &M);
    for(int i = 0; i < M; i++){
        scanf("%d", &query[i]);
    }
    merge(number_card, N);
    for(int i = 0; i < M; i++){
        int lower_idx = lower_search(query[i]);
        int upper_idx = upper_search(query[i]);
        printf("%d ", upper_idx - lower_idx);
    }
    printf("\n");
    return 0;
}