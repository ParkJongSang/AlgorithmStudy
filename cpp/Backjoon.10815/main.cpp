#include <cstdio>

typedef long long ll;

int N, M;
ll arr[500000];

void merge_sort(int left, int mid, int right){
    int i = left;
    int j = mid+1;
    int k = left;

    ll tmp[500000];

    while(i <= mid && j <= right){
        if(arr[i] <= arr[j]){
            tmp[k++] = arr[i++];
        }else{
            tmp[k++] = arr[j++];
        }
    }
    if(i <= mid){
        for(int s = i; s <= mid; s++){
            tmp[k++] = arr[s];
        }
    }else{
        for(int s = j; s <= right; s++){
            tmp[k++] = arr[s];
        }
    }
    for(int s = left; s <= right; s++){
        arr[s] = tmp[s];
    }
}

void partition(int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        partition(left, mid);
        partition(mid+1, right);
        merge_sort(left, mid, right);
    }
}

int bin_search(int key){
    int l = 0, r = N-1;
    while(l <= r){
        int mid = (l+r)/2;
        if(arr[mid] == key) return 1;
        else if(arr[mid] > key) r = mid-1;
        else if(arr[mid] < key) l = mid+1;
    }
    return 0;
}

int main(void){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%lld", &arr[i]);
    }
    partition(0, N-1);
    scanf("%d", &M);
    for(int i = 0; i < M; i++){
        int key; scanf("%d", &key);
        printf("%d ", bin_search(key));
    }
    printf("\n");
    return 0;
}