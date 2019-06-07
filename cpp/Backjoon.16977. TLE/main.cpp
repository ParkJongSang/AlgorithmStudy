#include <cstdio>
using namespace std;

int arr[100000];
int stack[100000];
int top = -1;
int bottom = -1;

int main() {
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d",&arr[i]);
    }
    int m; scanf("%d", &m);
    for(int i = 0; i < m; i++){
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        int ans = 0;
        int res = 0;
        top = bottom = -1;
        for (int i=a-1; i<=b-1; i++){
            int left = i;
            while(top != bottom && arr[stack[top]] > arr[i]) {
                int height = arr[stack[top]];
                top -= 1;
                int width = i - a + 1;
                if (top != bottom) {
                    width = i - stack[top] - 1;
                }
                if(width > c){
                     width = c;
                }
                if (width == c && ans < width*height) {
                    ans = width*height;
                    res = height;
                }
            }
            top += 1;
            stack[top] = i;
        }
        while(top != bottom) {
            int height = arr[stack[top]];
            top -= 1;
            int width = b - a + 1;
            if (top != bottom) {
                width = b - stack[top] - 1;
            }
            if(width > c){
                width = c;
            }
            if (width == c && ans < width*height) {
                ans = width*height;
                res = height;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}