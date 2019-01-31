#include <iostream>
#include <algorithm>

#define MAX 1000000

using namespace std;

long N, M;
long trees[MAX];

long solve(long m);

int main() {

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        cin >> trees[i];

    }

    sort(trees, trees+N);

    cout << solve(M);

    return 0;
}

long solve(long m){
    long sum;
    long start = 0;
    long end = trees[N-1];
    long cut_point;
    long ret = 0;
    while(start <= end){
        sum = 0;
        cut_point = (start+end)/2;

        for(int i = N-1; i >= 0; i--){
            if(trees[i] > cut_point){
                sum += trees[i] - cut_point;
            }
        }

        if(sum >= m){
            ret = max(ret, cut_point);
            start = cut_point+1;
        }else{
            end = cut_point-1;
        }
    }

    return ret;
}