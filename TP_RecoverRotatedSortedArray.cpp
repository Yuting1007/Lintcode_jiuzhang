class Solution {
public:
    /**
     * @param nums: An integer array
     * @return: nothing
     */
    void recoverRotatedSortedArray(vector<int> &nums) {
        // write your code here
        if(nums.size() == 0){
            return;
        }

        //find the offset
        //three-step-reverse
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i - 1]){
                int offset = i;
                reverse(nums, 0, offset - 1);
                reverse(nums, offset, nums.size() - 1);
                reverse(nums, 0, nums.size() - 1);
            }
        }
    }

private:
    void reverse(vector<int> &nums, int start, int end){
        if(start < 0 || end > nums.size()){
            return;
        }
        for(int i = start, j = end; i < j; i++, j--){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
};
