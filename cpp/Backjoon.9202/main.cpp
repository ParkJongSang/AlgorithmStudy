#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <memory.h>

using namespace std;

const int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dy[8] = {1, 0, -1, 0, -1, 1, -1, 1};
const int score[9] = {0, 0, 0, 1, 1, 2, 3, 5, 11};

string board[4];
bool visit[4][4];
set<string> res;

bool isInside(int y, int x){
    if(y >= 0 && y < 4 && x >= 0 && x < 4){
        return true;
    }
    return false;
}

struct Trie{
    bool finish;
    Trie *next[26];

    Trie() : finish(false){
        memset(next, 0, sizeof(next));
    }

    ~Trie() {
        for(int i = 0; i < 26; i++){
            if(next[i])
                delete next[i];
        }
    }

    void insert(const char *key){
        if(*key == '\0'){
            finish = true;
        }else{
            int cur = *key - 'A';
            if(next[cur] == NULL){
                next[cur] = new Trie();
            }
            next[cur] -> insert(key + 1);
        }
    }

    void search(int y, int x, string str){
        if(!isInside(y, x)){
            return;
        }
        if(visit[y][x] == 1){
            return;
        }
        if(str.length() > 8){
            return;
        }
        visit[y][x] = true;
        str = str + board[y][x];
        int cur_idx = board[y][x] - 'A';
        if(next[cur_idx] == NULL){
            visit[y][x] = false;
            return;
        }
        if(next[cur_idx] -> finish){
            res.insert(str);
        }
        for(int i = 0; i < 8; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            next[cur_idx] -> search(ny, nx, str);
        }
        visit[y][x] = false;
    }
};

int main(void){
    int words, N;
    cin >> words;
    Trie *root = new Trie;

    for(int i = 0; i < words; i++){
        char input[10];
        cin >> input;
        root -> insert(input);
    }

    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < 4; j++){
            cin >> board[j];
        }
        res.clear();
        for(int cy = 0; cy < 4; cy++){
            for(int cx = 0; cx < 4; cx++){
                root -> search(cy, cx, "");
            }
        }
        string longest = *(res.begin());
        int get_score = 0;
        for(auto it : res){
            if(longest.length() < it.length()){
                longest = it;
            }
            get_score += score[it.length()];
        }
        cout << get_score << " " << longest << " " << res.size() << "\n";
    }
    return 0;
}