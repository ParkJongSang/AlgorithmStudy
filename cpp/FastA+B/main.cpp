#include <iostream>

using namespace std;

long A, B;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int tc = 0;

    cin >> tc;

    for(int i = 0; i < tc; i++){
        cin >> A >> B;
        cout << A+B << "\n";
    }

    return 0;
}