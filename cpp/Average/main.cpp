#include <iostream>

using namespace std;

int N;
int arr[1000] = {0,};
int max_value = -1;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
        if(max_value < arr[i]){
            max_value = arr[i];
        }
    }

    double sum = 0;

    for(int i = 0; i < N; i++){
        sum += ((double)arr[i] / (double)max_value) * (double)100;
    }

    cout << sum / N;

    return 0;
}