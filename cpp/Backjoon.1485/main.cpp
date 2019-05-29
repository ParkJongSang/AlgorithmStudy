#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N;
int point[4][2];

void init(){
    for(int i = 0; i < 4; i++){
        point[i][0] = 100001;
        point[i][1] = 100001;
    }
}

long long getDist(int x1, int y1, int x2, int y2){
    return pow(x1-x2, 2) + pow(y1-y2, 2);
}

int isTrueSquare(){
    for(int i = 0; i < 4; i++){
        vector<long long> v;
        for(int j = 0; j < 4; j++){
            
            int k = (i + j) % 4;
            if(k == i) continue;
            v.push_back(getDist(point[i][0], point[i][1], point[k][0], point[k][1]));
        }
        sort(v.begin(), v.end());

        if(v[0] != v[1] || 2 * v[0] != v[2]){
            return 0;
        }
    }

    return 1;
}

int main(void){
    scanf("%d", &N);

    while(N--){
        init();
        for(int i = 0; i < 4; i++){
            scanf("%d %d", &point[i][0], &point[i][1]);
        }

        printf("%d\n", isTrueSquare());
    }
    return 0;
}
