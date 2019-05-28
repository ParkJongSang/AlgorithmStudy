#include <iostream>

using namespace std;

int a[100];
int b[100];
int length;
int result;

void dfs(int vertex){
    if(a[vertex] == 99 || b[vertex] == 99){
        result = 1;
        return ;
    }else{
        if(a[vertex] != -1){
            dfs(a[vertex]);
        }
        if(b[vertex] != -1){
            dfs(b[vertex]);
        }
    }
}
                

int main(void){
    int test_case;
    int count = 10;
    int num1, num2;
    while(count--){
        fill(a, a+100, -1);
        fill(b, b+100, -1);
        cin >> test_case >> length;
        result = 0;
        for(int i = 0; i < length; i++){
            cin >> num1 >> num2;
            if(a[num1] == -1){
                a[num1] = num2;
            }else{
                b[num1] = num2;
            }
        }
        dfs(0);

        cout << "#" << test_case << " " << result << "\n";
    }
    return 0;
}