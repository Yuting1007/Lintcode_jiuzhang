class Solution {
public:
    /**
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    int kthLargestElement(int k, vector<int> &nums) {
        // write your code here
        return helper(nums, 0, nums.size() - 1, nums.size() - k);
    }


private:

    int helper(vector<int> &nums, int start, int end, int k){
        int p = partition(nums, start, end);
        //if p is the kth largest
        if(p == k){
            return nums[p];
        }
        //look for the right
         else if(p < k){
            return helper(nums, p + 1, end, k);
        } else {
            //look for the left
            return helper(nums, start, p - 1, k);
        }
    }

    int partition(vector<int> &nums, int start, int end){
        //set a pivot
        int pivot = nums[end];
        int i = start;
        for(int j = start; j < end; j++){
            if(nums[j] < pivot){
                swap(nums[i++], nums[j]);
            }
        }
        //put the pivot in the final position
        swap(nums[i], nums[end]);
        return i;
    }
};
