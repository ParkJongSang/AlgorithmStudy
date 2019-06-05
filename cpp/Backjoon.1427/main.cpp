#include <cstdio>

char input[15];
int arr[10];

int get_length(char *str){
    int ret = 0;
    for(int i = 0; str[i]; i++){
        ret+=1;
    }
    return ret;
}

void merge_sort(int left, int right, int mid){
    int i, j, k;
    i = left;
    k = left;
    j = mid + 1;

    int tmp[10];

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

void merge(int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        merge(left, mid);
        merge(mid+1, right);
        merge_sort(left, right, mid);
    }
}

int main(void){
    scanf("%s", input);
    int length = get_length(input);
    for(int i = 0; i < length; i++){
        arr[i] = input[i]-'0';
    }
    merge(0, length-1);
    for(int i = 0; i < length; i++){
        printf("%d", arr[i]);
    }printf("\n");
    return 0;
}