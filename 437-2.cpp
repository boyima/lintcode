class Solution {
public:
    /**
     * @param pages: a vector of integers
     * @param k: an integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        // write your code here
        int n = pages.size();
        vector<int> sum_from_start(n, 0);
        sum_from_start[0] = pages[0];
        for(int i = 1; i < n; i++){
            sum_from_start[i] = sum_from_start[i - 1] + pages[i];
        }
        vector<vector<int>> dp (k + 1, vector<int>(n, INT_MAX));
        for(int j = 0; j < n; j++){
            dp[1][j] = sum_from_start[j];
        }
        for(int i = 2; i < k + 1; i++){
            dp[i][0] = sum_from_start[0];
            int left = 0;
            int right = 1;
            while(right < n){
                int curr = sum_from_start[right] - sum_from_start[left];
                dp[i][right] = min(max(dp[i - 1][left], curr), dp[i][right]);
                if(left < right  && dp[i - 1][left] < curr){
                    left++;
                }
                else{
                    right++;
                    if(left > 0){
                        left--;
                    }
                }
            }
        }
        return dp[k][n - 1];
    }
};
