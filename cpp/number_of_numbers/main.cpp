#include <iostream>

using namespace std;

int A, B, C;
int num[10];

void solve(int a, int b, int c){
    long long result = a * b * c;
    while(result > 0){
        num[result % 10] += 1;
        result /= 10;
    }

    return;
}

void print_arr(){
    for(int i = 0; i < 10; i++){
        cout << num[i] << "\n";
    }
}

int main(void){
    cin >> A >> B >> C;
    solve(A, B, C);
    print_arr();
    return 0;
}