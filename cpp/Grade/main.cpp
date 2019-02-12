#include <iostream>

using namespace std;

int N;

int main() {
    char *str = "FFFFFFDCBAA";

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;
    cout << str[N/10];
    return 0;
}