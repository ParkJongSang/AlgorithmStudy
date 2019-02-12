#include <iostream>

using namespace std;

char str[102];

int main() {
    cin >> str;
    int ret = 0;

    for(int i = 0; i < 102 && str[i] != NULL; i++){
        ret = ret + 1;
        if(str[i] == 'c'){
            if(str[i+1] == '='){
                i = i+1;
            }else if(str[i+1] == '-'){
                i = i+1;
            }
        }else if(str[i] == 'd' && str[i+1] == 'z' && str[i+2] == '='){
            i = i+2;
        }else if(str[i] == 'd' && str[i+1] == '-'){
            i = i+1;
        }else if(str[i] == 'l' && str[i+1] == 'j'){
            i = i+1;
        }else if(str[i] == 'n' && str[i+1] == 'j'){
            i = i+1;
        }else if(str[i] == 's' && str[i+1] == '='){
            i = i+1;
        }else if(str[i] == 'z' && str[i+1] == '='){
            i = i+1;
        }
    }

    cout << ret;

    return 0;
}