#include <cstdio>

using namespace std;

int main(void){
    int score;
    int sum = 0;
    for(int i = 0; i < 5; i++){
        scanf("%d", &score);
        if(score < 40){
            score = 40;
        }
        sum += score;
    }  
    printf("%d\n", sum / 5);
    return 0;
}