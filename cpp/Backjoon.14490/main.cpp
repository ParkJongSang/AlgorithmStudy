#include <iostream>
#include <string>

using namespace std;

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b, a%b);
}

int main(void){
    int a, b;
    int tmp;
    int div;
    string N, M;
    string str;
    bool flag = false;
    cin >> str;

    for(int i = 0; i < str.size(); i++){
        if(str[i] == ':'){
            flag = true;
            continue;
        }
        if(flag == false){
            N.push_back(str[i]);
        }else if(flag == true){
            M.push_back(str[i]);
        }
    }
    a = stoi(N); 
    b = stoi(M);

    if(a < b){
        tmp = a;
        a = b;
        b = tmp;
    }

    div = gcd(a, b);

    a = stoi(N);
    b = stoi(M);
    cout << a/div << ":" << b/div << endl;

    return 0;
}