#include <cstdio>

using namespace std;

int N;

int main(void){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        int tmp; scanf("%d", &tmp);
        for(int j = 0; j < tmp; j++){
            printf("=");
        }
        printf("\n");
    }
    return 0;
}