#include <cstdio>

int min(int a, int b){
    return a < b ? a : b;
}

int main(void){
    int burger[3], beverage[2];
    scanf("%d %d %d %d %d",&burger[0],&burger[1],&burger[2],&beverage[0],&beverage[1]);
    int minBurger = min(burger[0], min(burger[1], burger[2]));
    int minBeverage = min(beverage[0], beverage[1]);
    printf("%d\n", minBurger + minBeverage - 50);
    return 0;
}  