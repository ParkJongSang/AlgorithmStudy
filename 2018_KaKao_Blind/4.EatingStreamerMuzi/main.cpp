#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct food_st{
    int index;
    long long time;
};

bool cmpTime(food_st f1, food_st f2){
    return f1.time < f2.time;
}

bool cmpIdx(food_st f1, food_st f2){
    return f1.index < f2.index;
}

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    int len = food_times.size();
    vector<food_st> f;
    
    for(int i = 0; i < len; i++){
        f.push_back({i+1, food_times[i]});
    }
    sort(f.begin(), f.end(), cmpTime);
    
    int preTime = 0;
    int idx = 0;
    
    for(food_st f_st : f){
        long long diff = f_st.time - preTime;
        if(diff != 0){
            long long spend = diff * len;
            if(spend <= k){
                k -= spend;
                preTime = f_st.time;
            } else {
                k %= len;
                sort(f.begin()+idx, f.end(), cmpIdx);
                return f[idx+(int)k].index;
            }
        }
        idx++;
        len--;
    }
   
    return -1;
}