#include <cstdio>

typedef long long ll;

ll min(ll a, ll b){
    if(a > b) return b;
    return a;
}

ll max(ll a, ll b){
    if(a > b) return a;
    return b;
}

int main(void){
    ll min_num = 1000001;
    ll max_num = -1;
    int N; scanf("%d", &N);
    while(N--){
        int tmp; scanf("%d", &tmp);
        min_num = min(min_num, tmp);
        max_num = max(max_num, tmp);
    }
    printf("%lld\n", min_num * max_num);

    return 0;
}