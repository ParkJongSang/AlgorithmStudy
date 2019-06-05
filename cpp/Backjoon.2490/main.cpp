#include <cstdio>

using namespace std;

int main(void){
    int arr[4];
    
    for(int i = 0; i < 3; i++){
        int sum = 0;
        scanf("%d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3]);
        for(int j = 0; j < 4; j++) sum += arr[j];
        if(sum == 0){
            printf("D\n");
        }else if(sum == 1){
            printf("C\n");
        }else if(sum == 2){
            printf("B\n");
        }else if(sum == 3){
            printf("A\n");
        }else if(sum == 4){
            printf("E\n");
        }
    }

    return 0;
}