#include <cstdio>

int max(int a, int b){
    return a < b ? b : a;
}

int main(void){
    int l, a, b, c, d; scanf("%d %d %d %d %d", &l, &a, &b, &c, &d);
    int k_day = a / c;
    int m_day = b / d;
    if(a % c){
        k_day++;
    }
    if(b % d){
        m_day++;
    }
    printf("%d\n", l - max(k_day, m_day));
    return 0;
}