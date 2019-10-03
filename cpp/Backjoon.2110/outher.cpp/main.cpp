#include <vector>

using namespace std;

vector<int> check(int answer, int challenge){
    vector<int> ret(2);
    
    if(answer / 100 == challenge / 100) ret[0]++;
    if((answer%100) / 10 == (challenge%100) / 10) ret[0]++;
    if(answer%10 == challenge%10) ret[0]++;
    
    int a_hund = answer / 100;
    int a_ten = (answer%100) / 10;
    int a_one = answer % 10;
    
    int b_hund = challenge / 100;
    int b_ten = (challenge%100) / 10;
    int b_one = challenge % 10;
    
    if(a_hund == b_ten || a_hund == b_one) ret[1]++;
    if(a_ten == b_hund || a_ten == b_one) ret[1]++;
    if(a_one == b_ten || a_one == b_hund) ret[1]++;
    
    return ret;
}


int solution(vector<vector<int> > baseball) {
    int answer = 0;
    vector<int> v;
    for(int a = 1; a < 10; a++){
        for(int b = 1; b < 10; b++){
            for(int c = 1; c < 10; c++){
                if(a != c && a != b && b != c){
                    v.push_back(a*100 + b*20 + c*1);
                }
            }

    
    return answer;
}

int main(void){
    solution({{123, 1, 1}, {356, 1, 0}, {327, 2, 0}, {489, 0, 1}});
    return 0;
}
