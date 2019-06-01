#include <stdio.h>
#include <string.h>

#define mod 100019

using namespace std;

typedef struct Node{
    int id;
    char name[25];
    Node *next;
    
    Node(int n, char *s){
        id = n;
        int i;
        for(i = 0; s[i]; i++){
            name[i] = s[i];
        }
        name[i] = 0;
        next = NULL;
    }
};
Node* hashTable[mod];

int myHash(char *s){
    int ret = 0;
    for(int i = 0, k = 1; s[i]; i++){
        ret = (ret + k * s[i]) % mod;
        k = (k * 17) % mod;
    }
    return ret;
}

void addHashTable(Node *node, int key){
    if(hashTable[key] == NULL){
        hashTable[key] = node;
    }else{
        node -> next = hashTable[key];
        hashTable[key] = node;
    }
}

bool compareChar(char *str1, char *str2){
    for(int i = 0; str1[i]||str2[i]; i++){
        if(str1[i] != str2[i]) return false;
    }
    return true;
}

int findHashTable(char *s){
    int key = myHash(s);

    if(compareChar(s, hashTable[key] -> name)){
        return hashTable[key] -> id;
    }else{
        Node *node = hashTable[key] -> next;

        while(node != NULL){
            if(compareChar(s, node->name)){
                return node -> id;
            }
            node = node -> next;
        }
    }
    return -1;
}

int charToString(char *s){
    int ret = 0;
    for(int i = 0; s[i]; i++){
        ret *= 10;
        ret += s[i]-'0';
    }

    return ret;
}

int main(){
    char tab[100005][25];
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++){
        char pocket[25];
        scanf("%s", &pocket);

        int j;
        for(j = 0; pocket[j]; j++)
            tab[i][j] = pocket[j];
        tab[i][j] = 0;

        int key = myHash(pocket);
        Node *node = new Node(i, pocket);
        addHashTable(node, key);
    }

    for(int i = 0; i < m; i++){
        char pocket[25];
        scanf("%s", &pocket);

        if(pocket[0] >= '0' && pocket[0] <= '9'){
            int idx = charToString(pocket);
            printf("%s\n", tab[idx]);
        }else{
            printf("%d\n", findHashTable(pocket));
        }
    }

    return 0;
}