#include <cstdio>

int cur_people = 0;
int max_people = 0;

int max(int a, int b){
    if(a>b){
        return a;
    }
    return b;
}

int main(void){
    int enter = 0;
    int exit = 0;
    for(int i = 0; i < 4; i++){
        scanf("%d %d", &exit, &enter);
        cur_people -= exit;
        cur_people += enter;

        max_people = max(cur_people, max_people);
    }

    printf("%d\n", max_people);
    return 0;
}