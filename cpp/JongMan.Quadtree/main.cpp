#include <iostream>
#include <string>

using namespace std;


string reverse(string::iterator &it){
    char head = *it;
    ++it;
    if(head == 'b' || head == 'w'){
        return string(1, head);
    }
    string upperLeft = reverse(it);
    string upperRight = reverse(it);
    string lowerLeft = reverse(it);
    string lowerRight = reverse(it);

    return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int C; string str;
    cin >> C;
    while(C--){
        cin >> str;
        string::iterator it = str.begin();
        cout << reverse(it) << endl;
    }

    return 0;
}