#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
    int k, N, root, length;
    int *node;

    scanf("%d" , &k);

    N = pow(2,k) -1;
    root = N/2 + 1;

    node = (int *)malloc(sizeof(int) * (N+1));

    for(int i = 0; i < N; i++){
        scanf("%d", &node[i+1]);
    }

    for(int i = 0; i < k; i++){
        length = 0;
        for(int j = 0; j < pow(2,i); j++){
            printf("%d ", node[root+length]);
            length = (root*2)*(j+1);
        }
        root = root/2;
        printf("\n");
    }

    return 0;
}