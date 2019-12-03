class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> &numbers, int target) {
        // write your code here
        if(numbers.size() < 3) return -1;

        sort(numbers.begin(), numbers.end());

        int sum = numbers[0] + numbers[1] + numbers[2];
        for(int i = 0; i < numbers.size() - 2; i++){
            int left = i + 1;
            int right = numbers.size() - 1;
            while(left < right){
                int curr_sum = numbers[i] + numbers[left] + numbers[right];
                if(abs(sum - target) > abs(curr_sum - target)){
                    sum = curr_sum;
                }
                if(curr_sum > target){
                    right--;
                } else {
                    left++;
                }
            }
        }

        return sum;
    }
};
