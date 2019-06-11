#include <cstdio>

int visit[9];
int arr[9], buf[9];
int ans[7];
bool flag = false;


void merge(int *p, int len){
    if(len < 2) return;
    int i,j,k,mid;
    mid = len/2;
    merge(p, mid);
    merge(p+mid, len-mid);
    i = 0, j = mid, k = 0;
    while(i < mid && j < len){
        if(p[i] < p[j]){
            buf[k++] = p[i++];
        }else{
            buf[k++] = p[j++];
        }
    }
    while(i < mid) buf[k++] = p[i++];
    while(j < len) buf[k++] = p[j++];
    for(int i = 0; i < len; i++){
        p[i] = buf[i];
    }
}

bool check(int *p){
    int ret = 0;
    for(int i = 0; i < 7; i++){
        ret += p[i];
    }
    return ret == 100 ? true : false;
}

void dfs(int idx, int depth){
    if(depth == 7){
        flag = check(ans);
        return;
    }
    for(int i = idx; i < 9; i++){
        if(!visit[i]){
            visit[i] = 1;
            ans[depth] = arr[i];
            dfs(i+1, depth+1);
            if(flag == true) return;
            ans[depth] = 0;
            visit[i] = 0;
        }
    }
    return;
}
int main(void){
    for(int i = 0; i < 9; i++){
        scanf("%d", &arr[i]);
    }
    dfs(0, 0);
    merge(ans, 7);
    for(int i = 0; i < 7; i++){
        printf("%d\n", ans[i]);
    }
    return 0;
}