#include <iostream>
#include <algorithm>

using namespace std;

char gears[5][9];
int N;
int gear_num;
int dir;
int visit[5];

void changeGear(char *_gear, int _dir){
    if(_dir == 1){
        char temp = _gear[7];
        for(int i = 7; i > 0; i--){
            _gear[i] = _gear[i-1];
        }
        _gear[0] = temp;
    }else if(_dir == -1){
        char temp = _gear[0];
        for(int i = 0; i < 8; i++){
            _gear[i] = _gear[i+1];
        }
        _gear[7] = temp;
    }else if(_dir == 0){
        return;
    }
}

bool hasRight(int num){
    return num + 1 < 5;
}

bool hasLeft(int num){
    return num - 1 > 0;
}

void solve(int _gear_num, int _dir){
    if(visit[_gear_num] == 1){
        return;
    }
    if(_gear_num < 1 || gear_num >= 5){
        return;
    }
    visit[_gear_num] = 1;
    if(hasLeft(_gear_num) && visit[_gear_num - 1] == 0 && gears[_gear_num - 1][2] == gears[_gear_num][6]){
        solve(_gear_num - 1, 0);
    }else if(hasLeft(_gear_num) && visit[_gear_num - 1] == 0 && gears[_gear_num - 1][2] != gears[_gear_num][6]){
        solve(_gear_num - 1, -1 * _dir);
    }
    if(hasRight(_gear_num) && visit[_gear_num + 1] == 0 && gears[_gear_num + 1][6] == gears[_gear_num][2]){
        solve(_gear_num + 1, 0);
    }else if(hasRight(_gear_num) && visit[_gear_num + 1] == 0 && gears[_gear_num + 1][6] != gears[_gear_num][2]){
        solve(_gear_num + 1, -1 * _dir);
    }
    changeGear(gears[_gear_num], _dir);
}


int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    for(int i = 1; i <= 4; i++){
        //0 is N, 1 is S
        cin >> gears[i];
    }

    cin >> N;

    for(int i = 0; i < N; i++){
        //1 is clock, -1 is reverse-clock
        cin >> gear_num >> dir;
        for(int i = 1; i <= 4; i++){
            visit[i] = 0;
        }
        solve(gear_num, dir);

    }

    int a = (gears[1][0] - '0');
    int b = (gears[2][0] - '0') << 1;
    int c = (gears[3][0] - '0') << 2;
    int d = (gears[4][0] - '0') << 3;

    cout << a+b+c+d << "\n";

    return 0;
}