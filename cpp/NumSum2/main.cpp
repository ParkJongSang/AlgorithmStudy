#include <iostream>

using namespace std;


int main() {
    int N, M;
    int A[10000];
    long long sum = 0;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    int count = 0;
    int i = 0;
    int j = 0;
    sum = A[0];

    while(i <= j && j < N){
        if(sum == M){
            count += 1;
            j += 1;
            sum += A[j];
        }else if(sum < M){
            j += 1;
            sum += A[j];
        }else{
            sum -= A[i];
            i += 1;
            if(i > j && j < N){
                j += 1;
                sum += A[j];
            }
        }
    }

    cout << count;

    return 0;
}