#include <cstdio>

int N;
int input;
long long ans = 0;

int main(void){
    scanf("%d", &N);
    while(N--){
        scanf("%d", &input);
        ans = ((input / 3) * (input / 3 + 1) / 2 * 3
            + (input / 7) * (input / 7 + 1) / 2 * 7
            - (input / 21) * (input / 21 + 1) / 2 * 21);
            //(1~N까지 더하고*3+1~N까지 더하고*7)-1~N까지 더하고*21
        printf("%lld\n", ans);
    }
    return 0;
}