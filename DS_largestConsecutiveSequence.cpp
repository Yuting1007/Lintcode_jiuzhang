class Solution {
public:
    /**
     * @param num: A list of integers
     * @return: An integer
     */
    int longestConsecutive(vector<int> &nums) {
        // write your code here
        //insert all num in nums to the hashset
        unordered_set<int> h(nums.begin(), nums.end());
        int ans = 0;
        for(int num : nums){
            if(!h.count(num - 1)){
                int l = 0;
                while(h.count(num++)){
                    l++;
                }
                ans = max(ans, l);
            }
        }
        return ans;
    }
};
