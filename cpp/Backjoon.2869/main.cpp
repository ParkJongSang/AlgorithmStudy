#include <cstdio>

typedef long long ll;

ll solve(ll a, ll b, ll v){
    ll len = a - b;
    ll l , r;
    l = 0, r = 1000000000;
    while(l <= r){
        ll mid = (l + r) / 2;
        if(v - a <= len * mid){
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    return l;
}

int main(void){
    int a, b, v; scanf("%d %d %d", &a, &b, &v);
    printf("%lld\n", solve(a, b, v)+1);
    return 0;
}