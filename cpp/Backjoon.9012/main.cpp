#include <iostream>
#include <stack>
#include <string>

using namespace std;

int solve(string str){
    stack<char> st;
    
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '('){
            st.push(str[i]);
        }else if(st.size() > 0 && str[i] == ')' && st.top() == '('){
            st.pop();
        }else if(st.size() == 0 && str[i] == ')'){
            return 0;
        }
    }

    if(st.size() > 0){
        return 0;
    }
    return 1;
}

int main(void){
    int tc;
    string input;
    cin >> tc;

    for(int i = 0; i < tc; i++){
        cin >> input;
        if(solve(input) == 0){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }
    

    return 0;
}




// #include <stdio.h>
// #include <stdbool.h>
// #include <stdlib.h>

// int solution(int temperature[], int temperature_len, int A, int B) {
//     int answer = 0;
//     for(int i = 0; i < temperature_len; i++) {
//     	if(temperature[i] > temperature[A] && temperature[i] > temperature[B])
//     		answer += 1;
//     }
//     return answer;
// }

// // 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다. 아래에는 잘못된 부분이 없으니 위의 코드만 수정하세요.
// int main() {
// 	int temperature[] = {3, 2, 1, 5, 4, 3, 3, 2};
// 	int temperature_len = 8;
// 	int A = 1;
// 	int B = 6;
// 	int ret = solution(temperature, temperature_len, A, B);

// 	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
// 	printf("solution 함수의 반환 값은 %d 입니다.\n", ret);
// }