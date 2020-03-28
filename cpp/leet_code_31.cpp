class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-1;
        int j = nums.size()-1;
        while(i > 0 && nums[i] <= nums[i-1]) i -= 1;
        if(i <= 0) {
            while(i < j) {
                swap(nums[i], nums[j]);
                i += 1;
                j -= 1;
            }
        } else {
            while(nums[i-1] >= nums[j]) j -= 1;
            swap(nums[i-1], nums[j]);

            j = nums.size()-1;
            while(i < j) {
                swap(nums[i], nums[j]);
                i += 1;
                j -= 1;
            }
        }
    }
};
