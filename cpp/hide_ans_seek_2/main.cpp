#include <stdio.h>

int queue[100001], front = 0, rear = 0;
int dist[100001];
int cnt[100001];
int N, K;

void init(){
    for(int i = 0; i < 100001; i++){
        dist[i] = 100000;
    }
}
void solve(int n, int k){
    queue[rear++] = n;
    while(front != rear){
        int cur = queue[front];
        front++;
        int back = cur - 1;
        if(back >= 0 && dist[cur] + 1 < dist[back]){
            dist[back] = dist[cur] + 1;
            queue[rear++] = back;
        }
        if(dist[cur] + 1 == dist[back]){
            cnt[back]++;
        }else{
            cnt[back] = 1;
        }
        
        int teleport = cur * 2;
        if(teleport < 100001 && dist[cur] + 1 < dist[teleport]){
            dist[teleport] = dist[cur] + 1;
            queue[rear++] = teleport;
        }
        if(dist[cur] + 1 == dist[teleport]){
            cnt[teleport]++;
        }else{
            cnt[teleport] = 1;
        }
        int go = cur + 1;
        if(go < 100001 && dist[cur] + 1 < dist[go]){
            dist[go] = dist[cur] + 1;
            queue[rear++] = go;
        }
        if(dist[cur] + 1 == dist[go]){
            cnt[go]++;
        }else{
            cnt[go] = 1;
        }
    }
}
int main(void){
    init();
    scanf("%d %d", &N, &K);
    dist[N] = 0;
    solve(N,K);
    printf("%d\n%d\n", dist[K], cnt[K]);
    return 0;
}