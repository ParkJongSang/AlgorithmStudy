#include <cstdio>
#include <utility>
#include <memory.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

int N, M;
char com;
int a, b, w;
int parent[MAXN], level[MAXN];
ll weight[MAXN];

pair<int, ll> find(int x, int ret){
    if(x == parent[x])return make_pair(x, ret);
    return find(parent[x], ret + weight[x]);
}

void merge(int a, int b, int w){
    pair<int, ll> x = find(a, 0), y = find(b, 0);

    if(x.first == y.first) return;
   
    if(level[x.first] > level[y.first]){
        weight[y.first] -= (y.second - x.second - w);
        parent[y.first] = x.first;
        level[x.first] += level[y.first];
        level[y.first] = 1;
    }else{
        weight[x.first] += (y.second - x.second - w);
        parent[x.first] = y.first;
        level[y.first] += level[x.first];
        level[x.first] = 1;
    }
}

int main(void){ 
    while(scanf("%d %d", &N, &M), !(N == 0 && M == 0)) {
        memset(weight, 0, sizeof weight);
        for(int i = 1; i <= N; i++) parent[i] = i, level[i] = 1;

        for(int i = 0; i < M; i++){
            scanf(" %c", &com);

            if(com == '!'){
                scanf("%d %d %d", &a, &b, &w);
                merge(a, b, w);
            }else{
                scanf("%d %d", &a, &b);
                pair<int, ll> x = find(a,0);
                pair<int, ll> y = find(b,0);
                if(x.first != y.first){
                    printf("UNKNOWN\n");
                }else{
                    printf("%lld\n", y.second - x.second);
                }
            }
        }
    }
    return 0;
}