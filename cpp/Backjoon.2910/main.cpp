#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int N, C, X;
map<int, int> m;
map<int, int> m_pri;
vector<pair<int, int > > p;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return m_pri[a.second] < m_pri[b.second];
    }
    return a.first > b.first;
}

int main(void){
    scanf("%d %d", &N, &C);
    for(int i = 0; i < N; i++){
        scanf("%d", &X);
        m[X]++;
        if(!m_pri[X]){
            m_pri[X] = i + 1;
        }
    }
    for (auto i : m) 
        p.push_back(make_pair(i.second, i.first));
    sort(p.begin(), p.end(), cmp);
    for (auto i : p) {
        for (int j = 0; j < i.first; j++)
            printf("%d ", i.second);
    }
    printf("\n");
    return 0;
}
