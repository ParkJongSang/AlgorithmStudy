#include <iostream>
#include <string>

using namespace std;

int main(void){
    int cnt = 0;
    int N;
    int num = 666;

    cin >> N;

    while(cnt < N){
        string str = to_string(num);
        if(str.find("666") != string::npos){
            cnt++;
            if(cnt == N){
                cout << str << "\n";
                break;
            }
        }
        num++;
    }
    return 0;
}