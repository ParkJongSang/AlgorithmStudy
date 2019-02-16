#include <iostream>

using namespace std;

int num[100001], tc, x;
int arr[100001];

int main() {

    for(int i = 1; i <= 100001; i++){
        num[i] = i;
    }

    for(int i = 2; i <= 100001; i++){
        if(num[i] == 0){
            continue;
        }else{
            int j = i + i;
            while(j <= 100001){
                num[j] = 0;
                j += i;
            }
        }
    }

    cin >> tc;
    while(tc--){
        cin >> x;
        for(int i = 2; i < 100001; i++){
            if(num[i] == 0){
                continue;
            }
            if(x % num[i] == 0){
                x /= num[i];
                arr[i] += 1;
                i = 1;
            }
        }

        for (int i = 2; i < 100001; i++) {
            if (num[i] == 0)continue;
            if (arr[i] != 0)
                cout << i << ' ' << arr[i] << "\n";
        }

        for (int i = 2; i < 100001; i++) {
            if (num[i] == 0)continue;
            arr[i] = 0;
        }
    }

    return 0;
}