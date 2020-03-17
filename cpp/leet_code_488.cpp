class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ret;
        int len = nums.size();
        
        for(int i=0; i <len; i++){
          if(nums[abs(nums[i])-1]>0)   nums[abs(nums[i])-1]*=-1;
        }
        
        for(int i =0; i <len; i++){
          if(nums[i]>0) ret.push_back(i+1);
        }
        
        return ret;
    }
};
