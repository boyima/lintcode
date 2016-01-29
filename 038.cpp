class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        if(matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;
        int row = m - 1;
        int col = 0;
        while(row >= 0 && row <= m - 1 && col >= 0 && col <= n - 1){
            if(matrix[row][col] == target){
                res++;
                row--;
                col++;
            }
            else if(matrix[row][col] < target){
                col++;
            }
            else{
                row--;
            }
        }
        return res;
    }
};
