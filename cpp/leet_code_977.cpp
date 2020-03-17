class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int len = A.size();
        
        for(int i = 0; i < len; i++) {
            A[i] = A[i]*A[i];
        }
        sort(A.begin(), A.end());
        
        return A;
    }
};
