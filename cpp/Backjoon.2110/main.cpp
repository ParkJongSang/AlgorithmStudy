#include <cstdio>
#include <vector>

using namespace std;
#define MAX_L 200000

typedef long long ll;

int C, N;

int main(void){
    vector<ll> x_pos;
    scanf("%d %d", &N, &C);
    for(int i = 0; i < N; i++){
        ll tmp; 
        scanf("%lld", &tmp);
        x_pos.push_back(tmp);
    }
    sort(x_pos.begin(), x_pos.end());
    
    ll start = 1;
    ll end = x_pos[N-1] - x_pos[0];
    ll ans = 0;

    while(start <= end){
        ll mid = (start + end) / 2;
        ll cnt = 1;
        ll benchmark= x_pos[0];
        for(int i = 1; i < N; i++){
            ll dist = x_pos[i] - benchmark;
            if(mid <= dist){
                cnt+=1;
                benchmark = x_pos[i];
            }
        }
        if(cnt >= C){
            ans = mid;
            start = mid + 1;
        }else{
            end = mid -1;
        }
    }
    printf("%lld\n", ans);
    return 0;
}