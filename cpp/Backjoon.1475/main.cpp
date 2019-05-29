#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str;
int number[10];

int solve(string input){
    int length = input.length();
    int nine_or_six = 0;
    int others = 0;

    for(int i = 0; i < length; i++){
        number[input.at(i)-'0'] += 1;
    }
    
    if((number[6] + number[9]) % 2){
        number[6] = (number[6] + number[9])/2 + 1;
        number[9] = (number[6] + number[9])/2 + 1;
    }else{
        number[6] = (number[6] + number[9])/2;
        number[9] = (number[6] + number[9])/2;
    }
    nine_or_six = number[6];

    for(int i = 0; i < 10; i++){
        if(i == 6 || i == 9){
            continue;
        }
        others = max(others, number[i]);
    }

    return max(nine_or_six, others);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> str;
    cout << solve(str) << "\n";

    return 0;
}