class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        vector<int> init;
        
        if(numRows < 1) {
            return ret;
        }
        
        init.push_back(1);
        ret.push_back(init);
        
        for(int i = 1; i < numRows; i++) {
            vector<int> toAppend;
            toAppend.push_back(1);
            for(int j = 0; j < i-1; j++) {
                int toAddNumber = ret[i-1][j] + ret[i-1][j+1];
                toAppend.push_back(toAddNumber);
            }
            toAppend.push_back(1);
            ret.push_back(toAppend);
        }
        
        return ret;
    }
};
