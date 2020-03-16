class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> nonZero;
        vector<int> zero;
        int len = nums.size();
        
        for(int i = 0; i < len; i++) {
            if(nums[i] == 0) zero.push_back(nums[i]);
            else nonZero.push_back(nums[i]);
        }
        nums.clear();
        nums.insert(nums.end(), nonZero.begin(), nonZero.end());
        nums.insert(nums.end(), zero.begin(), zero.end());

    }
};
