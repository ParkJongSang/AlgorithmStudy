#include <iostream>
#include <string.h>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    char str[500+2];
    cin.getline(str, 500+2);
    while (strcmp(str, "END") != 0) {
        int length = strlen(str);
        while (length--) {
            cout << str[length];
        }
        cin.getline(str, 500+2);
        cout << "\n";
    }
}