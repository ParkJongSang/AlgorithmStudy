#include <iostream>

using namespace std;

int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int x, y;

int solve(int x, int y){
    int days = 0;
    for(int i = 1; i < x; i++){
        days += day[i];
    }
    days += y;

    return days % 7;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> x >> y;

    switch(solve(x, y)){
        case 0:
            cout << "SUN\n";
            break;
        case 1:
            cout << "MON\n";
            break;
        case 2:
            cout << "TUE\n";
            break;
        case 3:
            cout << "WED\n";
            break;
        case 4:
            cout << "THU\n";
            break;
        case 5:
            cout << "FRI\n";
            break;
        case 6:
            cout << "SAT\n";
            break;
    }

    return 0;
}