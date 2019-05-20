#include <iostream>

using namespace std;

string str;
int TC;

int getScore(string s){
    int score = 0;
    int ret = 0;
    int length = str.length();

    for(int i = 0; i < length; i++){
        if(s[i] == 'O'){
            score += 1;
        }else if(s[i] == 'X'){
            score = 0;
        }
        ret += score;
    }

    return ret;
}

int main(void){
    cin >> TC;

    while(TC--){
        cin >> str;
        cout << getScore(str) << "\n";
    }
    return 0;
}