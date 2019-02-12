#include <iostream>

using namespace std;

int N;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;
    char *num = new char[N];
    cin >> num;

    int ret = 0;

    for(int i = 0; i < N; i++){
        ret += num[i]-'0';
    }

    cout << ret << "\n";

    return 0;
}