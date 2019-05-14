#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct Trie {
    bool finish; //끝나는 지점 표시
    Trie* next[10]; //26개 알파벳
    Trie() : finish(false){
        memset(next, 0, sizeof(next));
    }

    ~Trie(){
        for(int i = 0; i < 10; i++)
            if(next[i])
                delete next[i];
    }

    void insert(const char *key){
        if(*key == '\0'){
            finish = true;//문자열이 끝나는 위치 표시
        }else{
            int cur = *key - '0';
            if(next[cur] == NULL){
                next[cur] = new Trie();//탐색이 처음 되는 지점인 경우 동적할당
            }
            next[cur] -> insert(key+1);//다음위치 삽입
        }
    }

    bool find(const char *key){
        if(*key == '\0') return 0;//문자열이 끝남
        if(finish) return 1;
        int cur = *key - '0';
        return next[cur] -> find(key+1);//다음위치 탐색
    }
};

int T, N, R;
char a[10000][11];
int main(void){
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        getchar();
        for(int i = 0; i < N; i++){
            scanf("%s", &a[i]);
        }
        Trie *root = new Trie;
        R = 0;
        for(int i = 0; i < N; i++){
            root -> insert(a[i]);
        }
        for(int i = 0; i < N; i++){
            if(root -> find(a[i])){
                R = 1;
            }
        }
        printf("%s\n", R?"NO":"YES");

    }
    return 0;
}