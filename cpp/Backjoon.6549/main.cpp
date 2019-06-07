#include <cstdio>
#include <algorithm>
#define MAX_N 100000
using namespace std;
typedef long long ll;
int n, a[MAX_N + 1], seg[4 * MAX_N];
void init(int node, int x, int y) {
    if (x == y)
        seg[node] = x;
    else {
        int mid = (x + y) >> 1;
        init(node * 2, x, mid);
        init(node * 2 + 1, mid + 1, y);
        if (a[seg[node * 2]] <= a[seg[node * 2 + 1]])
            seg[node] = seg[node * 2];
        else
            seg[node] = seg[node * 2 + 1];
    }
}

int query(int lo, int hi, int node, int x, int y) {
    if (y < lo || hi < x)
        return -1;
    if (lo <= x&&y <= hi)
        return seg[node];
    int mid = (x + y) >> 1;
    int q1 = query(lo, hi, node * 2, x, mid);
    int q2 = query(lo, hi, node * 2 + 1, mid + 1, y);
    if (q1 == -1)return q2;
    if (q2 == -1)return q1;
    if (a[q1] <= a[q2])
        return q1;
    return q2;
}

ll sol(int lo, int hi, int w) {
    int m = query(lo, hi, 1, 0, n - 1);
    ll res = 0;
    if(w == (hi - lo + 1)){
        res = (ll)(hi - lo + 1)*a[m];
    }
    
    if (lo <= m - 1) {
        ll ans = sol(lo, m - 1, w);
        res = max(res, ans);
    }
    if (m + 1 <= hi) {
        ll ans = sol(m + 1, hi, w);
        res = max(res, ans);
    }
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    init(1, 0, n - 1);
    int m; scanf("%d", &m);
    for(int i = 0; i < m; i++){
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        printf("%lld\n", sol(a-1, b-1, c));
    }
    
    
    return 0;
}