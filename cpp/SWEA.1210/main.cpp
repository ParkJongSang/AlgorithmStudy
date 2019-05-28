#include <iostream>

using namespace std;

int tc;
int arr[101][101];
int ans;

int init(){
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            arr[i][j] = 0;
        }
    }
    ans = -1;
}

bool is_inside(int y, int x){
    if(y >= 0 && y < 100 && x >= 0 && x < 100){
        return true;
    }
    return false;
}

bool has_right(int y, int x){
    if(is_inside(y, x+1) && arr[y][x+1]){
        return true;
    }
    return false;
}

bool has_left(int y, int x){
    if(is_inside(y, x-1) && arr[y][x-1]){
        return true;
    }
    return false;
}

void start(int y, int x){
    int cur_y = y;
    int cur_x = x;

    while(cur_y > 0){
        if(has_left(cur_y, cur_x)){
            while(arr[cur_y][cur_x-1] == 1){
                cur_x -= 1;
            }
        }else if(has_right(cur_y, cur_x)){
            while(arr[cur_y][cur_x+1] == 1){
                cur_x += 1;
            }
        }
        cur_y -= 1;
    }

    ans = cur_x;
}

int main(void){
    for(int T = 1; T <= 10; T++){
        init();
        cin >> tc;
        int start_y = -1;
        int start_x = -1;
        for(int i = 0; i < 100; i++){
            for(int j = 0; j < 100; j++){
                cin >> arr[i][j];
                if(arr[i][j] == 2){
                    start_y = i;
                    start_x = j;
                }
            }
        }
        start(start_y, start_x);

        cout << "#" << T << " " << ans << "\n";
    }
    return 0;
}