#include <iostream>

using namespace std;

int self_number[10001];

int d(int n){
    int num = n;
    int ret = n;
    while(num > 0){
        ret += num % 10;
        num /= 10;
    }
    return ret;
}

int main(void){
    for(int i = 0; i < 10001; i++){
        if(d(i) < 10001){
            self_number[d(i)] = 1;
        }
    }
    
    for(int i = 0; i < 10001; i++){
        if(self_number[i] != 1){
            cout << i << endl;
        }
    }
    return 0;
}