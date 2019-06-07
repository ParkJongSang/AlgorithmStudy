#include <stack>
#include <cstdio>

typedef long long ll;

using namespace std;

ll arr[100000];

int main(void){
    ll ans = 0;
    while(1){
        int N; scanf("%d", &N);
        if(N == 0) break;
        stack<ll> s;
        for(int i = 0; i < N; i++){
            scanf("%lld", &arr[i]);
        }
        ans = 0;
        for(int i = 0; i < N; i++){
            while(!s.empty() && arr[s.top()] > arr[i]){
                ll height = arr[s.top()];
                s.pop();
                ll width = i;
                if(!s.empty()){
                    width = i - s.top() - 1;
                }
                if(ans < width * height){
                    ans = width * height;
                }
            }
            s.push(i);
        }
        while(!s.empty()){
            ll height = arr[s.top()];
            s.pop();
            ll width = (ll)N;
            if(!s.empty()){
                width = (ll)N - s.top() - 1;
            }
            if(ans < width * height){
                ans = width * height;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}