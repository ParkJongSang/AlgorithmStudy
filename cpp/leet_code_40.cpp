class Solution {
public:
     void dfs(vector<int> &candidates,vector<int> &combination,vector<vector<int>> &result, int target,int startIndex){
        if(target < 0) {
            return;
        }
        if(target == 0){
            result.push_back(combination);
            return;
        }
        else{
            for(int i = startIndex; i < candidates.size(); i++) {
                if(i != startIndex && candidates[i] == candidates[i-1]) continue;
                combination.push_back(candidates[i]);
                dfs(candidates, combination, result, target - candidates[i], i+1);
                combination.pop_back();
            }
        }
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> combination;
        vector<vector<int>> ret;
        
        if(candidates.size() <= 0) {
            // do nothing
        } else {
            sort(candidates.begin(), candidates.end());
            dfs(candidates, combination, ret, target, 0); 
        }
        
        return ret;
    
    }
};
