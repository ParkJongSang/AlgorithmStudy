#include <cstdio>


int arr[100001];
int N, M;

void sort(int l, int r, int m){
    int i, j, k, s;
    i = l;
    j = m + 1;
    k = l;
    int tmp[100001];
    while(i <= m && j <= r){
        if(arr[i] <= arr[j]){
            tmp[k++] = arr[i++];
        }else{
            tmp[k++] = arr[j++];
        }
    }

    if(i > m){
        for(s = j; s <= r; s++){
            tmp[k++] = arr[s];
        }
    }else{
        for(s = i; s <= m; s++){
            tmp[k++] = arr[s];
        }
    }

    for(s = l; s <= r; s++){
        arr[s] = tmp[s];
    }
}
void merge(int l, int r){
    if(l < r){
        int m = (l + r) / 2;
        merge(l, m);
        merge(m+1, r);
        sort(l, r, m);
    }
}

int search(int key){
    int l = 0;
    int r = N-1;

    while(l <= r){
        int m = (l + r)/2;
        if(arr[m] > key){
            r = m - 1;
        }else if(arr[m] < key){
            l = m + 1;
        }else if(arr[m] == key){
            return 1;
        }
    }

    return 0;
}

void debug(){
    printf("\n");
    for(int i = 0; i < N; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void){
    scanf("%d", &N);
    int tmp;
    for(int i = 0; i < N; i++){
        scanf("%d", &tmp);
        arr[i] = tmp;
    }
    merge(0, N-1);

    scanf("%d", &M);
    for(int i = 0; i < M; i++){
        scanf("%d", &tmp);
        printf("%d\n", search(tmp));
    }
    return 0;
}