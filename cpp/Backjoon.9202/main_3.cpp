#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>

#define MAX_WORDS       300000
#define TABLE_SIZE      50000
#define PN              5381
#define MOD             50000

using namespace std;
typedef long long ll;

const int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dy[8] = {1, 0, -1, 0, -1, 1, -1, 1};
const int scoreTable[9] = {0, 0, 0, 1, 1, 2, 3, 5, 11};

vector<int> HASH_TABLE[TABLE_SIZE];
char words[MAX_WORDS+1][9];
bool visit[4][4];
bool wordChk[MAX_WORDS+1];

char boggle[4][5];

int score;
char ansWord[9];
int mxLen;
char tmpWord[10];
int hit;

int makeHash1(char *str) {
    ll ret = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++)
        ret = (ret * 13 + str[i]) % MOD + MOD;
 
    return (int)(ret % MOD);
}

int makeHash2(char *str) {
    ll ret = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++)
        ret = (ret * 177 + str[i]) % MOD + MOD;
 
    return (int)(ret % MOD);
}

void add_hash(char *str, int wordIdx){
    /* Index HASH_TABLE[key][0] is Chaining size */
    HASH_TABLE[makeHash1(str)].push_back(wordIdx);
}

bool is_Inside(int y, int x){
    if(y >= 0 && x >= 0 && y < 4 && x < 4){
        return true;
    }
    return false;
}

int contain(char *str){
    /* if HASH_TABLE contain str, return str's idx
        else return -1
     */
    
    int key1 = makeHash1(str);
    if(!HASH_TABLE[key1].empty()){
        for(int i = 0; i < HASH_TABLE[key1].size(); i++){
            if(strcmp(words[HASH_TABLE[key1][i]], str) == 0){
                return HASH_TABLE[key1][i];
            }
        }
    }
    return -1;
}

void solve(int y, int x, int depth){
    if(depth == 9) return;

    tmpWord[depth-1] = boggle[y][x];
    tmpWord[depth] ='\0';

    int idx = contain(tmpWord);

    if(idx >= 0){
        if(!wordChk[idx]){
            wordChk[idx] = true;
            score += scoreTable[depth];
            hit++;

            int tmpLen = strlen(tmpWord);
            if ( mxLen < tmpLen) {
                strcpy(ansWord, tmpWord);
                mxLen = tmpLen;
            }else if ( mxLen == tmpLen ){
                if (strcmp(ansWord, tmpWord) > 0){
                    strcpy(ansWord, tmpWord);
                }
            }
        }
    }

    for(int i = 0; i < 8; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(is_Inside(ny, nx) && visit[ny][nx] == 0){
            visit[ny][nx]=1;
            solve(ny, nx, depth+1);
            visit[ny][nx]=0;
        }
    }
    
}

int main(void){
    int N,T;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> words[i];
    }

    for(int i = 0; i < N; i++){
        add_hash(words[i], i);
    }

    cin >> T;
    for(int t = 0; t < T; t++){
        memset(wordChk, false, sizeof(wordChk));
        memset(ansWord, 0x00, sizeof(ansWord));
        score = 0;
        hit = 0;
        mxLen = 0;

        for(int i = 0; i < 4; i++){
            cin >> boggle[i];
        }

        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                visit[i][j] = 1;
                solve(i, j, 1);
                visit[i][j] = 0;
            }
        }
        cout << score << " " << ansWord << " " << hit << "\n";
    }
    return 0;
}
