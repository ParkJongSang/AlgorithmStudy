#include <iostream>
#include <string>

using namespace std;

int solve(string a, string b){
    int a_len = a.length();
    int b_len = b.length();
    int len = b_len - a_len;
    int ans = 987654321;
    for(int i = 0; i <= len; i++){
        int cnt = 0;
        for(int j = 0; j < a_len; j++){
            if(a[j] != b[i+j]){
                cnt++;
            }
        }
        ans = min(ans, cnt);
    }
    return ans;
}

int main(void){
    string a, b;
    cin >> a >> b;
    cout << solve(a, b) << "\n";
    return 0;
}