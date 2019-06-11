#include <cstdio>
typedef long long ll;

ll n;
ll m;
ll arr[10000];

ll max(ll a, ll b){
    return a > b ? a : b;
}

int main(void){
    ll start = 0;
    ll ans = 0;
    ll end = 0;
    scanf("%lld", &n);
    for(int i = 0; i < n; i++){
        scanf("%lld", &arr[i]);
        end = max(arr[i], end);
    }
    scanf("%lld", &m);
   
    while(start <= end){
        ll mid = (start + end) / 2;
        ll sum = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] > mid){
                sum += mid;
            }else{
                sum += arr[i];
            }
        }
        if(sum <= m){
            start = mid + 1;
            ans = max(ans, mid);
        }else{
            end = mid - 1;
        }
    }
    printf("%lld\n", ans);
    return 0;
}