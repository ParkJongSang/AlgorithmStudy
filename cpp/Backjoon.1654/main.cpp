#include <cstdio>

typedef long long ll;

int arr[10000];
int k, n;


bool can(ll mid){
    ll cnt = n;
    ll ret = 0;
    for(int i = 0; i < k; i++){
        ret += arr[i]/mid;
    }
    return ret >= cnt ? true : false;
}

ll max(ll a, ll b){
    return a > b ? a : b;
}

int main(void){
    scanf("%d %d", &k, &n);
    for(int i = 0; i < k; i++){
        scanf("%d", &arr[i]);
    }
    ll start = 0, end = 2147483648-1;
    ll ans = 0;
    while(start <= end){
        ll mid = (start + end) / 2;
        if(can(mid)){
            start = mid + 1;
            ans = max(ans, mid);
        }else{
            end = mid - 1;
        }
    }
    printf("%lld\n", ans);
    return 0;
}