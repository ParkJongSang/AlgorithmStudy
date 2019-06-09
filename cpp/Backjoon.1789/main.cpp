#include <cstdio>
typedef long long ll;
int main(void){
    ll n; scanf("%lld", &n);
    int ans = 0;
    ll sum = 0;
    for(int i = 1; sum <= n; i++){
        if(sum + i <= n){
            ++ans;
            sum += i;
        }else{
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}