#include <iostream>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD 300000

using namespace std;

struct Trie{
    int alpha[26];
    bool word;
    Trie(){
        word = false;
        for(int i = 0; i < 26; i++){
            alpha[i] = -1;
        }
    }
};

int trieIdx;
Trie trie[MAX_WORD*8 + 1];

char boggle[4][5];
bool wordChk[MAX_WORD*8 + 1];
bool v[4][4];

int scoreTable[10] = {0,0,0,1,1,2,3,5,11};
int score;
char ansWord[9];
int mxLen;
char tmpWord[9];
int hit;

void go(int x, int y, int depth, int idx){
    if(depth == 9) return;

    tmpWord[depth-1] = boggle[x][y];
    tmpWord[depth] = 0;

    if(trie[idx].word){
        if(wordChk[idx] == false){
            wordChk[idx] = true;
            score += scoreTable[depth];
            hit++;

            int tmpLen = strlen(tmpWord);

            if(mxLen < tmpLen){
                strcpy(ansWord, tmpWord);
                mxLen = tmpLen;
            }else if(mxLen == tmpLen){
                if(strcmp(ansWord, tmpWord) > 0){
                    strcpy(ansWord, tmpWord);
                }
            }
        }
    }

    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            int nx = x + i, ny = y + j;
            if(nx < 0 || ny < 0 || nx >= 4 || ny >= 4) continue;
            if(v[nx][ny]) continue;

            int nextIdx = trie[idx].alpha[boggle[nx][ny]-'A'];
            if(nextIdx == -1) continue;

            v[nx][ny] = 1;
            go(nx, ny, depth+1, nextIdx);
            v[nx][ny] = 0;
        }
    }
}

int main()
{
  int n;
  cin >> n;
 
  char words[(int)3e5][9];

  for (int i=0; i<n; i++)
  {
    cin >> words[i];
  }
 
  for (int i=0; i<n; i++)
  {
    int len = strlen(words[i]);
 
    Trie* cur = &trie[0];
    for (int j=0; j<len; j++)
    {
      int idx = (words[i][j]-'A');
      if ( cur->alpha[idx] == -1 ) cur->alpha[idx] = ++trieIdx;
      cur = &trie[cur->alpha[idx]]; 
    }
    cur->word = 1;
  }
 
  int T;
  cin >> T;
  for (int test_case=1; test_case<=T; test_case++)
  {
    memset(wordChk, false, sizeof(wordChk));
    memset(ansWord, 0, sizeof(ansWord));
    score= hit = mxLen= 0;
    for (int i=0; i<4; i++)
    {
      cin >> boggle[i];
    }
 
    for (int i=0; i<4; i++)
    {
      for (int j=0; j<4; j++)
      {
 
        int nextIdx = trie[0].alpha[boggle[i][j]-'A'];
        if (nextIdx == -1) continue;
 
        v[i][j]=1;
        go(i,j,1, nextIdx);
        v[i][j]=0;
      }
    }
    cout << score << " " << ansWord << " " << hit << "\n";
  }
}

