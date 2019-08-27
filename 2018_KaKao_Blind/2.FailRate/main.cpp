#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> unclears(N+2); 
    vector<int> clears(N+2); 
    vector<pair<double, int>> vec;
    
    for(int i=0; i<stages.size(); i++) {
        unclears[stages[i]]++;
    }
    
    clears[N+1] = unclears[N+1]; 
    for(int i=N; i>0; i--) {
        clears[i] = unclears[i] + clears[i+1];
    }
    
    for(int i=1; i<N+1; i++) {
        if(!clears[i])vec.push_back({0,i});
        else vec.push_back({(double)unclears[i]/clears[i], i});
    }
    
    sort(vec.begin(), vec.end(),
         [](pair<double, int> &a, pair<double, int> &b) {
             if(a.first == b.first) return a.second < b.second; 
             return a.first > b.first;
         }
    );
    
    for(int i=0; i<vec.size(); i++) {
        answer.push_back(vec[i].second);
    }
    
    return answer;
}