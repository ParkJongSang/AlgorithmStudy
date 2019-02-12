#include <iostream>

using namespace std;
int N;
int dp[1001] = {0, };

int solve(int num) {
    int hund = num / 100;
    num = num % 100;
    int ten = num / 10;
    num = num % 10;
    int one = num;

    int temp_a = hund - ten;
    int temp_b = ten - one;

    if(temp_a == temp_b){
        return 1;
    }else{
        return 0;
    }
}

int main() {
    cin >> N;
    for(int i = 1; i <= 1000; i++){
        if(i < 100){
            dp[i] = i;
        }else{
            dp[i] = dp[i-1] +solve(i);
        }
    }

    cout << dp[N];
    return 0;
}