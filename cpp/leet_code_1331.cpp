#include <map>

bool cmpByValue(const int &a, const int &b) {
    return a < b;
}

class Solution {
public:    
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> toSort;
        vector<int> ret;
        map<int, int> m;
        int len = arr.size();
        int rank = 1;
        
        toSort.insert(toSort.end(), arr.begin(), arr.end());
        sort(toSort.begin(), toSort.end(), cmpByValue);
        
        for(int i = 0; i < len; i++) {
            int key = toSort[i];
            if(m.count(key) == 0) m[key] = rank++;
        }
        
        for(int i = 0; i < len; i++) {
            int key = arr[i];
            ret.push_back(m[key]);
        }
        
        return ret;
    }
};
