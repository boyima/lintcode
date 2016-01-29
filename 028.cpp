class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        if(matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        if(target < matrix[0][0] || target > matrix[m - 1][n - 1]) return false;
        int mstart = 0;
        int mend = m - 1;
        while(mstart < mend - 1){
            if(matrix[mend][0] < target){
                mstart = mend;
                break;
            }
            int mmid = (mstart + mend) / 2;
            if(matrix[mmid][0] == target) return true;
            else if(matrix[mmid][0] > target){
                mend = mmid - 1;
            }
            else{
                mstart = mmid;
            }
        }
        int nstart = 0;
        int nend = n - 1;
        while(nstart <= nend){
            int nmid = (nstart + nend) / 2;
            if(matrix[mstart][nmid] == target) return true;
            else if(matrix[mstart][nmid] < target){
                nstart = nmid + 1;
            }
            else{
                nend = nmid - 1;
            }
        }
        return false;
    }
};
