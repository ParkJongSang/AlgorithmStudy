#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(void){
    int n, t;
    string str_1, str_2;
    cin >> n;
    for(int i = 0; i < n; i++){
        long long ans = 1;
        map<string, int> m;
        scanf("%d", &t);
        for(int j = 0; j < t; j++){
            cin >> str_1 >> str_2;
            m[str_2] += 1;
        }
        for(auto it = m.begin(); it != m.end(); it++){
            ans *= (1 + it -> second);
            //옷의 가지수 + 1(왜? 안입는 경우도 있으니까)
        }
        ans -= 1;
        //알몸인 경우가 하나 포함되어 있다. 제거
        printf("%lld\n", ans);
    }
    return 0;
}