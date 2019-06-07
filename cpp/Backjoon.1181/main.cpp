#include <cstdio>

char arr[20000][55];

int strlen(char *a){
    int ret = 0;
    for(int i = 0; a[i]; i++){
        ret++;
    }
    return ret;
}

void strcpy(char *dest, char *src){
    int s_len = strlen(src);
    for(int i = 0; i < s_len; i++){
        dest[i] = src[i];
    }
    dest[s_len] = '\0';
}

int strcmp(char *a, char *b){
    int i = 0;
    while(a[i] != '\0' || b[i] != '\0'){
        if(a[i] > b[i]) return a[i]-b[i];
        else if(a[i] < b[i]) return a[i]-b[i];
        i++;
    }
    return 0;
}

void m_sort(int left, int right, int mid){
    int i = left;
    int j = mid+1;
    int k = left;
    char tmp[20000][55];
    while(i <= mid && j <= right){
        if(strlen(arr[i]) < strlen(arr[j])){
            strcpy(tmp[k], arr[i]);
            k++; i++;
        }else if(strlen(arr[i]) > strlen(arr[j])){
            strcpy(tmp[k], arr[j]);
            k++; j++;
        }else{
            if(strcmp(arr[i],arr[j]) < 0){
                strcpy(tmp[k], arr[i]);
                k++; i++;
            }else{
                strcpy(tmp[k], arr[j]);
                k++; j++;
            }
        }
    }
    while(i <= mid){
        strcpy(tmp[k], arr[i]);
        k++; i++;
    }
    while(j <= right){
        strcpy(tmp[k], arr[j]);
        k++; j++;
    }
    for(int s = left; s <= right; s++){
        strcpy(arr[s], tmp[s]);
    }
}

void partition(int left, int right){
    if(left < right){
        int m = (left+right) / 2;
        partition(left, m);
        partition(m+1, right);
        m_sort(left, right, m);
    }
}


int main(void){
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", arr[i]);
    }
    partition(0, n-1);
    for(int i = 0; i < n; i++){
        printf("%s\n", arr[i]);
        int j = i;
        while(strcmp(arr[i], arr[j]) == 0){
            i++;
        }
        i--;
    }
    return 0;
} 