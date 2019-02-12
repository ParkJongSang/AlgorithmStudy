#include <iostream>

using namespace std;
int N, M;
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    while(1){
        cin >> N >> M;
        if(N == 0 && N == M){
            break;
        }
        cout << N+M << "\n";
    }

    return 0;
}