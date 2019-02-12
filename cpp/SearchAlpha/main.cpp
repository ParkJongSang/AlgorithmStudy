#include <iostream>

using namespace std;

int alpha[26];
char input[101];

int main() {

    cin >> input;

    for(int i = 0; i < 26; i++){
        alpha[i] = -1;
    }

    int idx = 0;

    while(idx < 101 && input[idx] != NULL){
        if(alpha[input[idx]-'a'] == -1){
            alpha[input[idx]-'a'] = idx;
        }
        idx++;
    }

    for(int i = 0; i < 26; i++){
        cout << alpha[i] << " ";
    }

    return 0;
}