#include <iostream>

using namespace std;

bool visit[10001];
int arr[100] = {0, };
int N;
int ans;
int sum;

void reset(){
    for(int i = 0 ; i < 10001; i++){
        visit[i] = false;
    }
    for(int i = 0; i < 100; i++){
        arr[i] = 0;
    }
    N = 0;
    ans = 0;
    sum = 0;
}

void init(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        sum += arr[i];
    }
}

void solve(){
    visit[0] = true;

    for(int i = 0; i < N; i++){
        for(int j = sum; j >= 0; j--){
            if(visit[j]){
                visit[j+arr[i]] = true;
            }
        }
    }
    return;
}

void check(){
    for(int i = 0; i <= sum; i++){
        if(visit[i]) ans++;
    }

}

void debug(){
    for(int i = 0; i < 10001; i++){
        if(visit[i]){
            cout << i << " ";
        }
    }
    cout << "\n";
}

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int tc;
    cin >> tc;

    for(int i = 1; i <= tc; i++){
        reset();
        init();
        solve();
        //debug();
        check();
        cout << "#" << i << " " << ans << "\n";
    }
}