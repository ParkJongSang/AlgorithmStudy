#include <stdio.h>

using namespace std;

int queue[100001], front = 0, rear = 0;
int dist[100001];
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
        int teleport = cur * 2;
        if(teleport < 100001 && dist[cur] < dist[teleport]){
            dist[teleport] = dist[cur];
            queue[rear++] = teleport;
        }
        int front = cur + 1;
        if(front < 100001 && dist[cur] + 1 < dist[front]){
            dist[front] = dist[cur] + 1;
            queue[rear++] = front;
        }
    }
}
int main(void){
    init();
    scanf("%d %d", &N, &K);
    dist[N] = 0;
    solve(N,K);
    printf("%d\n", dist[K]);
    return 0;
}