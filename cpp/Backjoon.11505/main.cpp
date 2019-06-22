#include <cstdio>

#define MAX_L 1000000
#define MOD 1000000007
typedef long long ll;

int arr[MAX_L];
ll seg_tree[MAX_L*4 + 12];
int N, M, K;

ll init(int start, int end, int node){
    if(start == end){
        return seg_tree[node] = (ll)arr[start];
    }else{
        int mid = (start+end)/2;
        return seg_tree[node] = ((init(start, mid, node*2)%MOD) * (init(mid+1,end,node*2+1)%MOD))%MOD;
    }
}

ll mul(int start, int end, int node, int left, int right){
    if(left > end || right < start){
        return 1;
    }
    if(left <= start && end <= right){
        return seg_tree[node];
    }
    int mid = (start+end)/2;
    return (mul(start, mid, 2*node, left, right) * mul(mid+1, end, 2*node+1, left, right)) % MOD;
}

ll update(int start, int end, int node, int index, ll input){
    if(!(start <= index && index <= end)){
        return seg_tree[node];
    }
    if(start == end){
        return seg_tree[node] = input;
    }
    int mid = (start+end) / 2;
    return seg_tree[node] = (update(start, mid, node*2, index, input) * update(mid+1, end, node*2+1, index, input)) % MOD;
}

int main(void){
    scanf("%d %d %d", &N, &M, &K);
    for(int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }
    int tc = M + K;
    init(0, N-1, 1);
    while(tc--){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if(a == 1){
            b--;
            arr[b] = c;
            update(0, N-1, 1, b, c);
        }else{
            b--; c--;
            printf("%lld\n", mul(0, N-1, 1, b, c));
        }
    }
    return 0;
}