class Solution {
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2
     * @return: nothing
     */
    void sortColors(vector<int> &nums) {
        // write your code here
        int size = nums.size();
        if(size == 0) return;

        int left = 0;
        int right = size - 1;
        int index = 0;

        while(index <= right){
            if(nums[index] == 0){
                swap(nums[index++], nums[left++]);
            } else if (nums[index] == 2){
                swap(nums[index], nums[right--]);
            } else {
                index++;
            }
        }
    }
};
