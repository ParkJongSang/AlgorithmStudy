#include <iostream>

using namespace std;

struct egg{
    int s;
    int w;
    bool state;
};

egg eggs[10];
egg back_up[10];
int N;
int ans = 0;
int cnt = 0;

void debug(){
    cout << "======" << endl;
    for(int i = 0; i < N; i++){
        cout << eggs[i].s << " ";
    }cout << endl;
}

int cnt_break(){
    int ret = 0;
    for(int i = 0; i < N; i++){
        if(eggs[i].state){
            ret++;
        }
    }
    return ret;
}

bool all_beeak(){
    bool flag = true;
    for(int i = 0; i < N; i++){
        if(eggs[i].state == false){
            flag = false;
            break;
        }
    }
    return flag;
}

void solve(int hand, int depth){
    ans = max(ans, cnt_break());
    if(depth >= N){
        return;
    }
    for(int i = 0; i < N; i++){
        if(eggs[hand].state == true){
            solve(hand+1, depth+1);
        }else if(i != hand && eggs[hand].state == false && eggs[i].state == false) {
            eggs[hand].s -= eggs[i].w;
            eggs[i].s -= eggs[hand].w;
            if (eggs[hand].s <= 0) {
                eggs[hand].state = true;
            }
            if (eggs[i].s <= 0) {
                eggs[i].state = true;
            }
            solve(hand + 1, depth + 1);
            eggs[hand].s += eggs[i].w;
            eggs[i].s += eggs[hand].w;
            if (eggs[hand].s > 0) {
                eggs[hand].state = false;
            }
            if (eggs[i].s > 0) {
                eggs[i].state = false;
            }
        }
    }
    return;
}

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    //init
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> eggs[i].s >> eggs[i].w;
        back_up[i].s = eggs[i].s;
        back_up[i].w = eggs[i].w;
        eggs[i].state = false;
        back_up[i].state = false;
    }

    solve(0,0);



    cout << ans << endl;

    return 0;
}