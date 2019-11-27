class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySum(vector<int> &nums) {
        // write your code here
        unordered_map<int, int> hash;
        vector<int> ans(2);
        int sum = 0;
        hash[0] = -1;

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(hash.find(sum) != hash.end()){
                ans[0] = hash[sum] + 1;
                ans[1] = i;
                break;
            } else {
                hash[sum] = i;
            }
        }
        return ans;
    }
};
