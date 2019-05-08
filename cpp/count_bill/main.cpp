#include <iostream>

using namespace std;

int N, M;
int ans;

void solve(){
    int cnt = N;
    int div = N / M;

    while(div != 0){
        cnt += div;
        div = div / M;
    }
    ans = cnt;
    return;
}

int main(void){
    cin >> N >> M;
    solve();
    cout << ans << "\n";
    return 0;
}