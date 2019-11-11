class Solution {
public:
    /**
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    vector<vector<int>> subsets(vector<int> &nums) {
        // write your code here
        vector<vector<int>> result;
        vector<int> path;
        std::sort(nums.begin(), nums.end());
        dfs(nums, 0, path, result);
        return result;
    }

    void dfs(vector<int> &nums, int index, vector<int> &path, vector<vector<int>> &result){
        //put the num[index]
        result.push_back(path);
        for(int i = index; i < nums.size(); i++){
            path.push_back(nums[i]);
            //the next level
            dfs(nums, i + 1, path, result);
            //back to the previous level
            path.pop_back();
        }
    }
};
