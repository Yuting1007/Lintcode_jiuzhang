class Solution {
public:
    /**
     * @param nums: an integer array
     * @return: nothing
     */
    void moveZeroes(vector<int> &nums) {
        // write your code here
        int left = 0;

        for(int right = 0; right < nums.size(); right++){
            if(nums[right]){
                swap(nums[left], nums[right]);
                left++;
            }
        }
    }
};
