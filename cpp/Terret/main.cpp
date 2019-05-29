#include <cstdio>
#include <cmath>

int x_1, y_1, r_1;
int x_2, y_2, r_2;
int N;

int solve(){
    int dist = (x_1-x_2)*(x_1-x_2) + (y_1-y_2)*(y_1-y_2);
    int r_dist = (r_1+r_2)*(r_1+r_2);

    //same circle
    if(x_1 == x_2 && y_1 == y_2 && r_1 == r_2){
        return -1;
    //outter, inner
    }else if(r_dist == dist || (sqrt(dist) + r_1 == r_2 || sqrt(dist) + r_2 == r_1)){
        return 1;
    //no meet
    }else if(r_dist < dist || (sqrt(dist) + r_1 < r_2 || sqrt(dist) + r_2 < r_1)){
        return 0;
    }
    return 2;
}

int main(void){
    scanf("%d", &N);

    while(N--){
        scanf("%d %d %d %d %d %d", &x_1, &y_1, &r_1, &x_2, &y_2, &r_2);
        printf("%d\n", solve());
    }  
    return 0;
}