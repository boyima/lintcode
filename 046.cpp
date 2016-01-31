class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        int n = nums.size();
        int res = nums[0];
        int count = 1;
        for(int i = 1; i < n; i++){
            if(nums[i] == res){
                count++;
            }
            else{
                count--;
                if(count == 0){
                    res = nums[i];
                    count = 1;
                }
            }
        }
        return res;
    }
};
