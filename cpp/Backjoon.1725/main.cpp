#include <cstdio>
#include <stack>
using namespace std;

int arr[100000];
int N;
stack<int> st;

int main(void){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        int left = i;
        while(!st.empty() && arr[st.top()] > arr[i]){
            int height = arr[st.top()];
            st.pop();
            int width = i;
            if(!st.empty()){
                width = (i - st.top() - 1);
            }
            if(ans < width * height){
                ans = width*height;
            }
        }
        st.push(i);
    }

    while(!st.empty()){
        int height = arr[st.top()];
        st.pop();
        int width = N;
        if(!st.empty()){
            width = N - st.top() -1;
        }
        if(ans < width * height){
            ans = width * height;
        }
    }

    printf("%d\n", ans);

    return 0;
}
