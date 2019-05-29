#include <cstdio>
#include <memory.h>

const int MAXN = 1e5 + 3;
char arr[MAXN][88];
bool ini;
int n, ans;

struct Trie{
    bool valid;
    bool exist;
    int branch;
    Trie* next[26];
    Trie() : valid(false), exist(false), branch(0){
        memset(next, 0, sizeof(next));
    }
    ~Trie() {
        for(int i = 0; i < 26; i++){
            if(next[i]) delete next[i];
        }
    }

    void insert(const char* key){
        if(*key == '\0') {
            valid = true;
        }else{
            int curr = *key - 'a';
            if(next[curr] == NULL){
                branch++;
                next[curr] = new Trie();
            }
            exist = true;
            next[curr] -> insert(key + 1);
        }
    }
    Trie *find(const char *key){
        if(*key == '\0') {
            return this;
        }
        if(ini) {
            ans++;
            ini = false;
        }else{
            if(branch >= 2) ans++;
            else if(valid) ans++;
        }
        int curr = *key - 'a';
        return next[curr] -> find(key + 1);
    }
};

int main(void){
    int N;
    while(scanf("%d", &N) != -1){
        Trie *root = new Trie;
        for(int i = 0; i < N; i++){
            scanf(" %s", &arr[i]);
            root -> insert(arr[i]);
        }
        int total = 0;
        for(int i = 0; i < N; i++){
            ini = true;
            ans = 0;
            root -> find(arr[i]);
            total += ans;
        }

        printf("%.2lf\n", (double)total / N);
        delete root;
    }
    return 0;
}