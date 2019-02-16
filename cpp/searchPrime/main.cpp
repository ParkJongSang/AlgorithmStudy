#include <iostream>

using namespace std;

int num[1001], tc, x, cnt = 0;


int main() {

    for(int i = 1; i <= 1000; i++){
        num[i] = i;
    }

    for(int i = 2; i <= 1000; i++){
        if(num[i] == 0){
            continue;
        }else{
            int j = i + i;
            while(j <= 1000){
                num[j] = 0;
                j += i;
            }
        }
    }

    cin >> tc;
    for(int i = 0; i < tc; i++){
        cin >> x;
        if(num[x] != 0 && x >= 2){
            cnt += 1;
        }
    }
    cout << cnt;

    return 0;
}