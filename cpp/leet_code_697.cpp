#define DEGREE 0
#define LEFT 1
#define RIGHT 2

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, int[3]> mp;
        
        for(int i = 0; i < nums.size(); i++) {
            if(mp.find(nums[i]) == mp.end()) {
                mp[nums[i]][DEGREE] = 1;
                mp[nums[i]][LEFT] = i;
                mp[nums[i]][RIGHT] = i;
            } else {
                mp[nums[i]][DEGREE] += 1;
                mp[nums[i]][LEFT] = i;
            }
        }
        
        int ret = nums.size();
        int degree = 0;
        
        for(auto it = mp.begin(); it != mp.end(); it++) {
            if(it->second[DEGREE] > degree) {
                degree = it->second[DEGREE];
                ret = it->second[LEFT] - it->second[RIGHT] + 1;
            } else if (it -> second[DEGREE] == degree) {
                ret = min(ret, it->second[LEFT] - it->second[RIGHT] + 1);
            }
        }
        
        return ret;
    }
};
