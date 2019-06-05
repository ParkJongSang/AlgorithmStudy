#include <stack>
#include <cstdio>

typedef long long ll;

using namespace std;

int main(void){
    int N;
    while(1){
        scanf("%d", &N);
        if(!N) break;
        stack<pair<int, int> > st;
        ll ans = 0;
        for(int i_idx = 0; i_idx <= N; i_idx++){
            int i_height;
            if(i_idx < N){
                scanf("%d", &i_height);
            }else{
                i_height = -1;
            }
            int left = i_idx;
            while(!st.empty() && st.top().second > i_height){
                ans = max(ans, ((ll)i_idx - st.top().first) * st.top().second);
                left = st.top().first;
                st.pop();
            }
            st.push(make_pair(left, i_height));
        }
        printf("%lld\n", ans);
    }
    return 0;
}