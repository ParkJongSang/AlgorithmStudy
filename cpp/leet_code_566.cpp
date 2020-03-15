#include <queue>

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int matrixR = nums.size();
        int matrixC = nums[0].size();
        vector<vector<int>> ret;
        queue<int> linearMatrix;
        
        if(matrixR * matrixC != r * c) {
            return nums;
        }
        
        for(int i = 0; i < matrixR; i++) {
            for(int j = 0; j < matrixC; j++) {
                linearMatrix.push(nums[i][j]);
            }
        }
        
        for(int i = 0; i < r; i++) {
            vector<int> toAppend;
            for(int j = 0; j < c; j++) {
                toAppend.push_back(linearMatrix.front());
                linearMatrix.pop();
            }
            ret.push_back(toAppend);
        }
        
        return ret;
    }
};
