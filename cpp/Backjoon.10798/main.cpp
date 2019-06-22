#include <cstdio>

char input[5][20];

int main(void){
    int flag = 1;
    int a = 0,b = 0,c = 0,d = 0,e = 0;
    for(int i = 0; i < 5; i++){
        scanf("%s", input[i]);
    }
    while(flag){
        flag = 0;
        if(input[0][a] != '\0'){
            printf("%c", input[0][a++]);
            flag = 1;
        }
        if(input[1][b] != '\0'){
            printf("%c", input[1][b++]);
            flag = 1;
        }
        if(input[2][c] != '\0'){
            printf("%c", input[2][c++]);
            flag = 1;
        }
        if(input[3][d] != '\0'){
            printf("%c", input[3][d++]);
            flag = 1;
        }
        if(input[4][e] != '\0'){
            printf("%c", input[4][e++]);
            flag = 1;
        }
    }
    printf("\n");
    return 0;
}