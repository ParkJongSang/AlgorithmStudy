#include <iostream>

using namespace std;

int cache[1001];
int mul[1001];
int N, M;
long long ans = 0;

void debug(){
    for(int i = 0; i <= N; i++){
        cout << cache[i] << " ";
    }cout << endl;
}

void solve(){
    for(int i = 0; i < M; i++){
        int tmp = mul[i];
        while(tmp <= N){
            cache[tmp] = 1;
            tmp += mul[i];
        }
    }

    for(int i = 0; i <= N; i++){
        if(cache[i] == 1){
            ans += i;
        }
    }

    return;
}

int main(void){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> mul[i];
    }
    solve();
    cout << ans << "\n";
    return 0;
}