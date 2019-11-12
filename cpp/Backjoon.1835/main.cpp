#include <iostream>

using namespace std;

int main(void){
    int N;
    int idx = 0;
    int cur_num = 1;
    int cur_size = N;
    int arr[10000] = {0, };
    int cnt = 0;

    cin >> N;
    
    while(cur_num <= N){
        cnt = 0;
        while(cnt < cur_num){
            if(arr[idx] == 0){
                cnt++;
			}
            idx++;
            if(idx >= N){
                idx = 0;
            }
        }
        while(arr[idx] > 0){
            idx++;
            if(idx >= N){
                idx = 0;
            }
        }
        arr[idx] = cur_num;
        cur_num++;
    }

    for(int i = 0; i < N; i++){
        cout << arr[i] << " ";
    }
    cout <<"\n";

    return 0;
}