#include <iostream>

using namespace std;

char str[102];

int main() {
    cin >> str;
    for(int i = 0; i < 102 && str[i] != NULL; i++){
        if(i == 0){
            cout << str[i];
        }else if(str[i] == '-'){
            cout << str[i+1];
        }

    }
    return 0;
}