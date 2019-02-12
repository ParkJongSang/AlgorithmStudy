#include <iostream>

using namespace std;
int A, B, C;
int main() {
    cin >> A >> B >> C;
    //첫째 줄에 (A+B)%C, 둘째 줄에 (A%C + B%C)%C, 셋째 줄에 (A×B)%C, 넷째 줄에 (A%C × B%C)%C를 출력한다.
    cout << (A+B)%C << endl;
    cout << ((A%C)+(B%C))%C << endl;
    cout << (A*B)%C << endl;
    cout << ((A%C)*(B%C))%C << endl;

    return 0;
}