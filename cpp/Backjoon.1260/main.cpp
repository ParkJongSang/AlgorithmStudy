#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX_L 1100

using namespace std;

vector<int> v[1001];
int visit[1001];

int N, M, V;

int q[MAX_L];
int front = 0;
int rear = 0;

void push(int key){
    q[rear++] = key;
}
void pop(){
    front++;
}

void bfs(int start){
    visit[start] = 1;
    push(start);
    while(front != rear){
        int cur_vertex = q[front];
        printf("%d ", cur_vertex);
        pop();
        for(int i = 0; i < v[cur_vertex].size(); i++){
            int next_vertex = v[cur_vertex][i];
            if(visit[next_vertex] == 0){
                visit[next_vertex] = 1;
                push(next_vertex);
            }
        }
    }
}

void dfs(int start){
    visit[start] = 1;
    printf("%d ", start);
    for(int i = 0; i < v[start].size(); i++){
        int next_vertex = v[start][i];
        if(visit[next_vertex] == 0){
            dfs(next_vertex);
        }
    }
}

void merge(vector<int> v, int left, int right){
    if(right - left < 1) return;
    int i, j, k, mid;
    mid = (right+left)/2;
    merge(v, left, mid);
    merge(v, mid, right);
    i = left; j = mid;
    vector<int> buf;
    while(i < mid && j < right){
        if(v[i] < v[j]){
            buf.push_back(v[i++]);
        }else{
            buf.push_back(v[j++]);
        }
    }
    while(i < mid){
        buf.push_back(v[i++]);
    }
    while(j < right){
        buf.push_back(v[j++]);
    }
    for(int i = left; i < right; i++){
        v[i] = buf[i];
    }
}

void init_visit(){
    for(int i = 1; i <= N; i++){
        visit[i] = 0;
    }
}

int main(void){
    scanf("%d %d %d", &N, &M, &V);
    for(int i = 0; i < M; i++){
        int start, end;
        scanf("%d %d", &start, &end);
        v[start].push_back(end);
        v[end].push_back(start);
    }
    for(int i = 1; i <= N; i++){
        sort(v[i].begin(), v[i].end());
    }
    init_visit();
    dfs(V); printf("\n");
    init_visit();
    bfs(V); printf("\n");

    return 0;
}


