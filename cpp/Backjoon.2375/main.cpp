#include <cstdio>
#include <vector>

using namespace std;

int N, M;
vector<int> arr;

struct SegmentTree{
    vector<int> maxTree;
    vector<int> minTree;

    SegmentTree(const vector<int> &array){
        int n = array.size();
        maxTree.resize(4*n + 12);
        minTree.resize(4*n + 12);
        init(array, 0, n-1, 1);
    }

    void init(const vector<int> &array, int left, int right, int node){
        init_min(array, left, right, node);
        init_max(array, left, right, node);
    }

    int init_min(const vector<int> &array, int left, int right, int node){
        if(left == right){
            return minTree[node] = array[left];
        }
        int mid = (left + right) / 2;
        int leftMin  = init_min(array, left, mid, node*2);
        int rightMin = init_min(array, mid+1, right, node*2 + 1);
        return minTree[node] = min(leftMin, rightMin);
    }

    int init_max(const vector<int> &array, int left, int right, int node){
        if(left == right){
            return maxTree[node] = array[left];
        }
        int mid = (left + right) / 2;
        int leftMax = init_max(array, left, mid, node*2);
        int rightMax = init_max(array, mid+1, right, node*2 + 1);
        return maxTree[node] = max(leftMax, rightMax);
    }


    int query_max(int left, int right, int node, int node_left, int node_right){
        if(right < node_left || left > node_right){
            return -1;
        }
        if(node_right <= right && node_left >= left){
            return maxTree[node];
        }
        int mid = (node_left + node_right) / 2;
        int leftMax = query_max(left, right, node*2, node_left, mid);
        int rightMax = query_max(left, right, node*2+1, mid+1, node_right);
        return max(leftMax, rightMax);
    }

    int query_min(int left, int right, int node, int node_left, int node_right){
        if(right < node_left || left > node_right){
            return 1100000000;
        }
        if(node_right <= right && node_left >= left){
            return minTree[node];
        }
        int mid = (node_left + node_right) / 2;
        int leftMin = query_min(left, right, node*2, node_left, mid);
        int rightMin = query_min(left, right, node*2+1, mid+1, node_right);
        return min(leftMin, rightMin);
    }
};

int main(void){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
        int a; scanf("%d", &a);
        arr.push_back(a);
    }
    SegmentTree st = SegmentTree(arr);
    for(int i = 0; i < M; i++){
        int a, b; scanf("%d %d", &a, &b);
        printf("%d %d\n", 
            st.query_min(a-1, b-1, 1, 0, arr.size()-1), 
            st.query_max(a-1, b-1, 1, 0, arr.size()-1));
    }

    return 0;
}