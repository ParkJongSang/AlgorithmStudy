#include <iostream>

using namespace std;

int map[101][101];
int target_y, target_x;

void backtrack(int y, int x){

}

int solve(int y, int x){
    int cy = y;
    int cx = x;

    while(cy > 1){
        if(cx-1 >= 1 && map[cy][cx-1] == 1){
            while(map[cy][cx-1] == 1){
                cx -= 1;
            }
        }else if(cx+1 < 101 && map[cy][cx+1] == 1){
            while(map[cy][cx+1] == 1){
                cx += 1;
            }
        }
        cy -= 1;
    }

    return cx;
}

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int cnt = 10;
    int tc;


    while(cnt--){
        cin >> tc;
        for(int y = 1; y < 101; y++){
            for(int x = 1; x < 101; x++){
                cin >> map[y][x];
                if(map[y][x] == 2){
                    target_y = y;
                    target_x = x;
                }
            }
        }
        cout << "#" << tc << " " << solve(target_y, target_x)-1<< "\n";
    }
    return 0;
}