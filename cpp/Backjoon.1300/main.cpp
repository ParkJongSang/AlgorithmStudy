#include <cstdio>

typedef long long ll;

ll min(ll a, ll b){
    return a < b ? a : b;
}

int main(void){
    ll n,k; scanf("%lld %lld", &n, &k);
    ll ans = n*n;
    ll start = 1;
    ll end = n*n;
    while(start <= end){
        ll cnt = 0;
        ll mid = (start + end) / 2;
        for(ll i = 1; i <= n; i++){
            //배열을 직접 그려보면 이해가 갈것
            //n*n배열 내에서 mid보다 작은 값의 개수를 결과로 내놓음
            ll num = mid / i;
            if(num > n){
                num = n;
            }
            cnt += num;
        }
        if(cnt < k){
            start = mid + 1;
        }else{
            ans = min(ans,mid);
            end = mid - 1;
        }
    }

    printf("%lld\n", ans);

    return 0;
}