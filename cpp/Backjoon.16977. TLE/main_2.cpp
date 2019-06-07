#include <cstdio>
#include <algorithm>
#define MAX_L 100000
#define MAX(a, b) a > b ? a : b

typedef long long ll;

int arr[MAX_L];
int tree[MAX_L*4 + 12];
int n, m;
using namespace std;

void init(int node, int left, int right){
    if(left == right){
        tree[node] = left;
    }else{
        int mid = (left + right) / 2;
        init(node*2, left, mid);
        init(node*2+1, mid+1, right);
        if(arr[tree[node*2]] <= arr[tree[node*2+1]]){
            tree[node] = tree[node*2];
        }else{
            tree[node] = tree[node*2+1];
        }
    }
}

int query(int node, int start, int end, int i, int j) {
    if (i > end || j < start) {
        return -1;
    }
    if (i <= start && end <= j) {
        return tree[node];
    }
    int m1 = query(2*node, start, (start+end)/2, i, j);
    int m2 = query( 2*node+1, (start+end)/2+1, end, i, j);
    if (m1 == -1) {
        return m2;
    } else if (m2 == -1) {
        return m1;
    } else {
        if (arr[m1] <= arr[m2]) {
            return m1;
        } else {
            return m2;
        }
    }
}
pair<int, ll> highest(int left, int right, int width){
   int m = query(1, 0, n-1, left, right); 
   ll area = right;
   int ret = -1;
   int w = right-left+1;
   if(w > width){
       w = width;
   }
   area = (ll)w * (ll)arr[m];
   ret = arr[m];
   int com_l = m - 1;
   int com_r = m + 1;
   while(com_l >= left-1 && arr[com_l] == arr[m]){
       com_l--;
   }
   while(com_r <= right-1 && arr[com_r] == arr[m]){
       com_r++;
   }
   //printf("%d\n", ret);
   if(left <= com_l && com_l - left + 1 >= w){
       pair<int, ll> tmp = highest(left, com_l, width);
       if (area < tmp.second) {
            area = tmp.second;
            ret = tmp.first;
        }
   }
   if(com_r <= right && right - com_r + 1 >= w){
       pair<int, ll> tmp = highest(com_r, right, width);
       if (area < tmp.second) {
            area = tmp.second;
            ret = tmp.first;
        }
       
   }
   pair<int, ll> tmp = make_pair(ret, area);

   return tmp;
}

int main(void){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    init(1, 0, n-1);
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        printf("%d\n", highest(a-1, b-1, c).first);
    }
    return 0;
}