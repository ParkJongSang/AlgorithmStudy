#include <cstdio>
#include <vector>

using namespace std;

int N, M;
vector<int> arr;

struct SegmentTree{
    int n;
    vector<int> rangeMin;

    SegmentTree(const vector<int> &array){
        n = array.size();
        rangeMin.resize(n*4 + 12);
        init(array, 0, n-1, 1);
    }

    int init(const vector<int> &array, int left, int right, int node){
        if(left == right){
            return rangeMin[node] = array[left];
        }
        int mid = (left + right) / 2;
        int leftMin = init(array, left, mid, node * 2);
        int rightMin = init(array, mid+1, right, node*2 + 1);
        return rangeMin[node] = min(leftMin, rightMin);
    }

    int query(int left, int right, int node, int node_left, int node_right){
        if(right < node_left || left > node_right){
            return 987654321;
        }
        if(left <= node_left && right >= node_right){
            return rangeMin[node];
        }
        int mid = (node_left + node_right) / 2;
        return min(query(left, right, node * 2, node_left, mid), query(left, right, node*2+1, mid+1, node_right));
    }

    int query(int left, int right){
        return query(left, right, 1, 0, n-1);
    }
};

int main(void){
    scanf("%d %d", &N, &M);

    for(int i = 0; i < N; i++){
        int tmp; scanf("%d", &tmp);
        arr.push_back(tmp);
    }

    SegmentTree minTree = SegmentTree(arr);

    for(int i = 0; i < M; i++){
        int a, b; scanf("%d %d", &a, &b);
        printf("%d\n", minTree.query(a-1, b-1));
    }

    return 0;
}