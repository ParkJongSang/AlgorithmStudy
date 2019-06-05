#include <cstdio>

using namespace std;

int main(void){
    int cnt = 0;
    int N, arr[5];
    scanf("%d", &N);
    for(int i = 0; i < 5; i++){
        scanf("%d", &arr[i]);
        if(arr[i] == N) cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}