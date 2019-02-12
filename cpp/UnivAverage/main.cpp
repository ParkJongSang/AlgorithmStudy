#include <iostream>
#include <math.h>
using namespace std;

int N;
int arr[1000] = {0, };

int main() {
    int tc = 0;
    cin >> tc;
    cout << fixed;
    cout.precision(3);
    for(int i = 0; i < tc; i++){
        cin >> N;
        int sum = 0;
        for(int j = 0; j < N; j++){
            cin >> arr[j];
            sum += arr[j];
        }

        double avr = (double)sum / (double)N;

        int count = 0;
        for(int j = 0; j < N; j++){
            if(avr < (double)arr[j]){
                count += 1;
            }
        }
        double ret= ((double)count / (double)N) * 100;

        cout << round(ret*1000)/1000 << "%\n";
    }
    return 0;
}