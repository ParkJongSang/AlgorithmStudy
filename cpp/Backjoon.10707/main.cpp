#include <cstdio>

int min(int a, int b){
    return a < b ? a : b;
}

int main(void){
    int a,b,c,d,p; scanf("%d %d %d %d %d", &a, &b, &c, &d, &p);
    int x = a * p;
    int y = b;
    if(p > c){
        y = b + ((p - c) * d);
    }
    printf("%d\n", min(x, y));
    return 0;
}