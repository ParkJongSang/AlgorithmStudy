#include <cstdio>
#include <algorithm>

int arr[13];
int visit[50];
int k;

void dfs(int idx, int depth){
    if(depth == 6){
        for(int i = 1; i < 50; i++){
            if(visit[i] == 1){
                printf("%d ", i);
            }
        }
        printf("\n");
        return;
    }

    for(int i = idx; i < k; i++){
        if(visit[arr[i]] == 0){
            visit[arr[i]] = 1;
            dfs(i+1, depth+1);
            visit[arr[i]] = 0;
        }
    }
    return;
}

int main(void){
    while(true){
        scanf("%d", &k);
        if(k == 0) break;
        for(int i = 0; i < k; i++){
            scanf("%d", &arr[i]);
        }
        dfs(0, 0);
        printf("\n");
    }
    return 0;
}