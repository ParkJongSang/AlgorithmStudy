#include <iostream> 

using namespace std;

int N;
long long ans = 1;

int main(void){
    cin >> N;
    
    for(int i = 1; i <= N; i++){
        ans *= i;
    }

    cout << ans << "\n";

    return 0;
}