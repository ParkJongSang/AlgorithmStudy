#include <iostream>
#include <string>
#include <algorithm>

#define MAX 20

using namespace std;

int iN;
int iOperNum;
int iAnswer = -987654321987654321;
int iArrNum[MAX], iArrOper[MAX];

void init(){
    cin >> iN;
    int iIdx = 0;
    int iIdx2 = 0;

    string Inp;
    cin >> Inp;
    for(int i = 0; i < Inp.size(); i++){
        if(i%2 == 0) iArrNum[iIdx++] = Inp[i]-'0';
        else iArrOper[iIdx2++] = Inp[i];
    }
    iOperNum = iN/2;
}

int calc(int a, int b, char c){
    if(c=='+') return a + b;
    if(c=='-') return a - b;
    if(c=='*') return a * b;
}

void dfs(int idx, int result){
    if(idx >= iOperNum){
        iAnswer = max(iAnswer, result);
        return;
    }

    int Cur_Result = calc(result, iArrNum[idx+1], iArrOper[idx]);
    dfs(idx+1, Cur_Result);
    if(idx+1 < iOperNum){
        int After_Result = calc(iArrNum[idx+1], iArrNum[idx+2], iArrOper[idx+1]);
        int Cur_Result = calc(result, After_Result, iArrOper[idx]);
        dfs(idx+2, Cur_Result);
    }
}

void solution(){
    if(iN==1){
        cout << iArrNum[0] << endl;
        return;
    }else if(iN==3){
        cout << calc(iArrNum[0], iArrNum[1], iArrOper[0]) << endl;
        return;
    }
    dfs(0, iArrNum[0]);
    cout << iAnswer << endl;
}
void solve(){
    init();
    solution();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}
