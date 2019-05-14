#include <iostream>

using namespace std;

int N;
int cnt_two = 0;
int cnt_five = 0;

int min(int a, int b){
    if(a > b){
        return b;
    }
    return a;
}

void solve(int n){
    if(n == 0){
        return;
    }
    if(n == 1){
        return;
    }
    int tmp = n;
    while(tmp % 2 == 0){
        tmp /= 2;
        cnt_two += 1;
    }
    while(tmp % 5 == 0){
        tmp /= 5;
        cnt_five += 1;
    }
    solve(n-1);
}

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;
    solve(N);
    int ans = min(cnt_two, cnt_five);
    cout << ans << "\n";
    return 0;
}