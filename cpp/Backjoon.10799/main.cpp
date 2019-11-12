#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void){
    int ans = 0;
    string input = "";
    stack<char> st;

    cin >> input;

    for(int i = 0; i < input.size(); i++){
        if(input[i] == '(' && input[i+1] == ')'){
            //cut
            ans += st.size();
            i = i+1;
        }else if(input[i] == '('){
            st.push(input[i]);
        }else if(input[i] == ')'){
            st.pop();
            ans += 1;
        }
        
    }

    cout << ans << endl;
    
    return 0;
}