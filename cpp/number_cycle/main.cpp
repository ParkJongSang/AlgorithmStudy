#include <iostream>

using namespace std;

int N;
int ans;

void solve(int n){
    int cnt = 0;
    int init_number = n;
    int ten = n / 10;
    int one = n % 10;

    int new_number = one * 10 + ((ten + one) % 10);

    while(new_number != init_number){
        cnt += 1;
        ten = new_number / 10;
        one = new_number % 10;
        new_number = one * 10 + ((ten + one) % 10);
    }
    cnt += 1;
    ans = cnt;
    return;
}

int main(void){
    cin >> N;
    solve(N);
    cout << ans << "\n";
    return 0;
}