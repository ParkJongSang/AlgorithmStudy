#include <iostream>

#define WON 10000

using namespace std;

int N;
int firstFestival[101] = { 0,
    500,
    300, 300,
    200, 200, 200,
    50, 50, 50, 50,
    30, 30, 30, 30, 30,
    10, 10, 10, 10, 10, 10,
};
int secondFestival[65] = { 0,
    512,
    256, 256,
    128, 128, 128, 128,
    64, 64, 64, 64, 64, 64, 64, 64,
    32, 32, 32, 32, 32, 32, 32, 32,
    32, 32, 32, 32, 32, 32, 32, 32,
};

int main(void){
    
    cin >> N;
    for(int i = 0; i < N; i++){
        int A, B;
        cin >> A >> B;
        
        cout << (firstFestival[A] + secondFestival[B]) * WON << "\n";
    }
    
    return 0;
}