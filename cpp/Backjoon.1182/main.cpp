#include <cstdio>

int visit[20];
int arr[20];
int tmp[20];
int ans = 0;
int n, s;

bool check(int len){
    int ret = 0;
    for(int i = 0; i < len; i++){
        ret += tmp[i];
    }
    return ret == s ? true : false;
}

void debug(int len){
    for(int i = 0; i < len; i++){
        printf("%d ", tmp[i]);
    }
    printf("\n");
}

void dfs(int idx, int depth){
    if(depth > n) return;
    if(check(depth) && depth > 0){
        ans++;
    }
    for(int i = idx; i < n; i++){
        if(!visit[i]){
            visit[i] = 1;
            tmp[depth] = arr[i];
            dfs(i+1, depth+1);
            tmp[depth] = 0;
            visit[i] = 0;
        }
    }
}

int main(void){
    scanf("%d %d", &n, &s);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    dfs(0,0);
    printf("%d\n", ans);
    return 0;
}