#include <cstdio>

typedef long long ll;
int arr_a[50];
int arr_b[50];
int N;
void merge_sort(int *arr, int left, int right, int mid){
    int i, j, k;
    i = left;
    k = left;
    j = mid + 1;

    int tmp[50];

    while(i <= mid && j <= right){
        if(arr[i] <= arr[j]){
            tmp[k++] = arr[j++];
        }else{
            tmp[k++] = arr[i++];
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

void merge(int *arr, int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        merge(arr, left, mid);
        merge(arr, mid+1, right);
        merge_sort(arr, left, right, mid);
    }
}

ll calc(int *arr_1, int *arr_2){
    int l = 0;
    int r = N-1;
    ll ret = 0;

    while(l < N && r >= 0){
        ret += arr_1[l++] * arr_2[r--];
    }
    return ret;
}

int main(void){
    scanf("%d", &N);
    
    for(int i = 0; i < N; i++){
        scanf("%d", &arr_a[i]);
    }
    for(int i = 0; i < N; i++){
        scanf("%d", &arr_b[i]);
    }
    merge(arr_a, 0, N-1);
    merge(arr_b, 0, N-1);
    
    printf("%lld\n", calc(arr_a, arr_b));

    return 0;
}
