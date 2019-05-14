#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

//트리의 각 노드 번호와 구조 초기화
long long init(vector<long long> &a, vector<long long> &tree, int node, int start, int end){
    //start ~ end 범위를 가진 node
    if(start == end){
        //리프노드일 경우
        return tree[node] = a[start];
    }else{
        return tree[node] = init(a, tree, node*2, start, (start+end)/2) + init(a, tree, node*2 + 1, (start+end)/2+1, end);
    }
}

//합 구하기
//[left, right]와 [start, end]가 겹치지 않는 경우
//[left, right]와 [start, end]를 완전히 포함하는 경우
//[start, end]가 [left, right]를 완전히 포함하는 경우
//[left, right]와 [start, end]가 겹쳐져 있는 경우

long long sum(vector<long long> &tree, int node, int start, int end, int left, int right){
    if(left > end || right < start){
        return 0;
    }
    if(left <= start && end <= right){
        return tree[node];
    }
    return sum(tree, node*2, start, (start+end)/2, left, right) + sum(tree, node*2 + 1, (start+end)/2 + 1, end, left, right);
}

//바꾸려는 위치의 값과 넣으려는 값의 차이(diff)를 해당 위치에 더해준다.
void update(vector<long long> &tree, int node, int start, int end, int index, long long diff){
    if(index < start || index > end) return;
    tree[node] = tree[node] + diff;
    if(start != end){
        update(tree, node*2, start, (start+end)/2, index, diff);
        update(tree, node*2+1, (start+end)/2+1, end, index, diff);
    }
}

int main(){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    vector<long long> a(n); //N개의 숫자
    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h+1)); //세그먼트 트리의 노드의 갯수
    vector<long long> tree(tree_size); 
    m += k;
    for(int i = 0; i < n; i++){
        scanf("%lld", &a[i]);
    }
    init(a, tree, 1, 0, n-1);
    while(m--){
        int t1, t2, t3;
        scanf("%d", &t1);
        if(t1 == 1){
            int t2;
            long long t3;
            scanf("%d %lld", &t2, &t3);
            t2 -= 1;
            long long diff = t3-a[t2];
            a[t2] = t3;
            update(tree, 1, 0, n-1, t2 ,diff);
        }else if(t1 == 2){
            int t2, t3;
            scanf("%d %d", &t2, &t3);
            printf("%lld\n", sum(tree, 1, 0, n-1, t2-1, t3-1));
        }
    }
    return 0;
}
