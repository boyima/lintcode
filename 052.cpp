class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
     */
    vector<int> nextPermutation(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        if(n < 2) return nums;
        int start = n - 1;
        while(start > 0){
            if(nums[start - 1] < nums[start]) break;
            start--;
        }
        start--;
        if(start < 0){
            reverse(nums.begin(), nums.end());
            return nums;
        }
        int mindiff = INT_MAX;
        
        int move = start;
        for(int i = start + 1; i < n; i++){
            int diff = nums[i] - nums[start];
            if(nums[i] > nums[start] && diff <= mindiff){
                move = i;
                mindiff = diff;
            }
        }
        swap(nums[start], nums[move]);
        reverse(nums.begin() + start + 1, nums.end());
        return nums;
    }
};
