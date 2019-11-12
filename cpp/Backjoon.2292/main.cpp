#include <iostream>

typedef long long ll;
using namespace std;

ll N;
int main(void){
    ll i = 1;
    ll left = 1;
    ll tmp = 1;
    ll ans = 0;
    cin >> N;

    while(1){
        if(left >= N){
            ans = i;
            break;
        }
        tmp = 6*(i++);
        left += tmp;
    }

    cout << ans << endl;

    return 0;
}