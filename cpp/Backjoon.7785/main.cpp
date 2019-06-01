#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>

using namespace std;

set<string> s;
vector<string> v;

int main(void){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        string name, com;
        cin >> name >> com;

        if(com == "enter"){
            s.insert(name);
        }else{
            s.erase(name);
        }
    }

    for(auto it = s.begin(); it != s.end(); it++){
        v.push_back(*it);
    }

    reverse(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++){
        cout << v[i] << "\n";
    }
    return 0;
}