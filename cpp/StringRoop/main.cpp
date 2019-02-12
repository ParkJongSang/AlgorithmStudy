#include <iostream>

using namespace std;

int N;
char str[22];

int main() {
    int tc = 0;
    cin >> tc;

    for(int i = 0; i < tc; i++){
        cin >> N >> str;
        int idx = 0;
        while(str[idx] != NULL){
            for(int j = 0; j < N; j++){
                cout << str[idx];
            }
            idx += 1;
        }
        cout << "\n";
    }
    return 0;
}