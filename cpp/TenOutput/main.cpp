#include <iostream>
#include <string>

using namespace std;

char *str = new char[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> str;

    for(int i = 0; i < 101; i++){
        if(str[i] != NULL){
            cout << str[i];
        }else{
            break;
        }
        if(i % 10 == 9){
            cout << "\n";
        }
    }

    return 0;
}