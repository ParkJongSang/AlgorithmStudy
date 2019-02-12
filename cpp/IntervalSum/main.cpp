#include <iostream>

using namespace std;

long sum[100001];
int num[100001];
int N;
int tc;
int a;
int b;

long solve(int a, int b){
    return sum[b] - sum[a-1];
}

int main() {

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> tc;

    for(int i = 1; i <= N; i++){
        cin >> num[i];
    }

    sum[1] = num[1];
    for(int i = 2; i <= N; i++){
        sum[i] = sum[i-1] + num[i];
    }

    for(int i = 1; i <= tc; i++){
        cin >> a >> b;
        cout << solve(a,b) << "\n";
    }
    return 0;
}