#include <cstdio>
#define MAX(a, b) a > b ? a : b
char str[1000000+10];
int arr[26];
int ans_size = 0;
int ans[26];

int main(void){
    scanf("%s",str);
    for(int i = 0; str[i]; i++){
        if(str[i] < 'a'){
            arr[str[i]-'A']++;
        }else{
            arr[str[i]-'a']++;
        }
    }
    int max = -1;
    for(int i = 0; i < 26; i++){
        max = MAX(max, arr[i]);
    }
    for(int i = 0; i < 26; i++){
        if(max == arr[i]){
            ans[ans_size++] = i;
        }
    }
    if(ans_size > 1){
        printf("?\n");
    }else{
        printf("%c\n",ans[0]+'A');
    }
    return 0;
}