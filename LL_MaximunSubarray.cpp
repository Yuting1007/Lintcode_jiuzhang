class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> &nums) {
        // write your code here
        int sum = 0;
        int minSun = 0;//can not set to INT_MAX since maxSum initialized first
        int maxSum = INT_MIN;

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            maxSum = max(maxSum, sum - minSun);
            minSun = min(minSun, sum);
        }
        return maxSum;
    }
};
