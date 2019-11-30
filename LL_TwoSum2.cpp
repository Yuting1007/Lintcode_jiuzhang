class Solution {
public:
    /**
     * @param nums: an array of Integer
     * @param target: target = nums[index1] + nums[index2]
     * @return: [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        int left = 0;
        int right = nums.size() - 1;
        vector<int> res(2);
        while(left < right){
            if(nums[left] + nums[right] == target){
                res[0] = left + 1;
                res[1] = right + 1;
                return res;
            } else if(nums[left] + nums[right] > target) {
                right--;
            } else {
                left++;
            }
        }
    }
};
