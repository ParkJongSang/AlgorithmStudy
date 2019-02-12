#include <iostream>

using namespace std;
int solve(int n);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    cout << solve(N);


    return 0;
}

int solve(int n){
    if(n % 5 == 0){
        return n / 5;
    }else{
        int x = n / 5;
        while(x >= 0){
            if((n - (x * 5)) % 3 == 0){
                int y = (n - (x * 5)) / 3;
                return x + y;
            }else{
                x--;
            }
        }
    }
    return -1;
}