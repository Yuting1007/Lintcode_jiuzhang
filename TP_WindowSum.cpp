class Solution {
public:
    /**
     * @param nums: a list of integers.
     * @param k: length of window.
     * @return: the sum of the element inside the window at each moving.
     */
    vector<int> winSum(vector<int> &nums, int k) {
        // write your code here
        vector<int> res;
        int n = nums.size();
        if (n < 0 || n == 0) return res;

        //get the sum[0]
        int sum = 0;
        for(int i = 0; i < k; i++){
            sum += nums[i];
        }
        res.push_back(sum);
        //get the rest sum;
        for(int i = 1; i < n - k + 1; i++){
            sum = sum - nums[i - 1] + nums[k + i - 1];
            res.push_back(sum);
        }
        return res;
    }
};
