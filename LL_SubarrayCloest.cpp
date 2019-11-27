class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> &nums) {
        // write your code here
        vector<int> res(2);
        vector<pair<int, int>> table;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            //if we have 0 as num, return i (the subarray is [:i])
            if(sum == 0){
                res[1] = i;
                return res;
            } else {
                table.push_back({sum, i});
            }
        }

        //sort the table to avoid the absolute value
        sort(table.begin(), table.end());
        int minDiff = INT_MAX;
        //find the minDiff
        for(int j = 1; j < table.size(); j++){
            int diff = table[j].first - table[j - 1].first;
            if(diff < minDiff){
                minDiff = diff;
                res[0] = min(table[j - 1].second, table[j].second) + 1;
                res[1] = max(table[j - 1].second, table[j].second);
            }
        }
        return res;
    }
};
