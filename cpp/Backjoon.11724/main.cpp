#include <cstdio>

class vector{
public:
    int capacity, sz;
    int *vc;

    vector() {
        capacity = 8;
        sz = 0;
        vc = new int[capacity];
    }
    ~vector() {
        delete[] vc;
    }

    void push_back(int val){
        if(capacity == sz){
            capacity *= 2;
            int *tmp = new int[capacity];
            for(int i = 0; i < sz; i++){
                tmp[i] = vc[i];
            }delete[] vc;
            vc = tmp;
        }
        vc[sz++] = val;
    }

    int front(){
        return vc[0];
    }

    int back(){
        return vc[sz-1];
    }

    int pop_back(){
        return vc[sz--];
    }

    int size() {
        return sz;
    }
    bool empty(){
        return !sz;
    }
    void clear(){
        sz = 0;
    }
    int &operator[](int i){
        return vc[i];
    }
};

vector v[1001];
int visit[1001];
int q[1020];
int front = 0, rear = 0;

void bfs(int vertex){
    front = rear = 0;
    q[rear++] = vertex;
    while(front != rear){
        int cur_vertex = q[front++];
        for(int i = 0; i < v[cur_vertex].size(); i++){
            int next_vertex = v[cur_vertex][i];
            if(visit[next_vertex] == 0){
                visit[next_vertex] = 1;
                q[rear++] = next_vertex;
            }
        }
    }
}

int main(void){
    int n,m; scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        int a, b; scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(visit[i] == 0){
            ans += 1;
            visit[i] = 1;
            bfs(i);
        }
    }
    printf("%d\n", ans);
    return 0;
}