//O(n^2*k)

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
        int sum = 0;
        int maxVal = 0;
        int dp[k + 1][n + 1];
        for(int i = 1; i <= n; i++){
            sum = sum + pages[i - 1];
            dp[1][i] = sum;
            maxVal = max(maxVal, pages[i - 1]);
        }
        if(k >= n){
            return maxVal;
        }
        for(int i = 2; i <= k; i++){
            for(int j = n - 1; j >= i - 1; j--){
                int cur = pages[j];
                int minVal = max(dp[i - 1][j], cur);
                for(int l = j - 1; l >= i - 1; l--){
                    cur = cur + pages[l];
                    int curMin = max(dp[i - 1][l], cur);
                    if(curMin < minVal){
                        minVal = curMin;
                    }
                }
                dp[i][j + 1] = minVal;
            }
        }
        return dp[k][n];
    }
};
