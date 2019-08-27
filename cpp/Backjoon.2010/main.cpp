#include <iostream>

using namespace std;

int N;
int arr[500000] = {0, };
int ans = 0;

using namespace std;

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    
    for(int i = 0; i < N; i++){
        ans += arr[i] - 1;
    }
    cout << ans + 1 << "\n";
    return 0;
}
