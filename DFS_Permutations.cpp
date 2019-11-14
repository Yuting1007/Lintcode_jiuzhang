class Solution {
public:
    /*
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int>> permute(vector<int> &nums) {
        // write your code here
        vector<vector<int>> res;
        vector<int> curr;
        set<int> visited;

        std::sort(nums.begin(), nums.end());
        dfs(nums, curr, visited, res);
        return res;
    }

private:
    void dfs(vector<int> &nums, vector<int> &curr, set<int> &visited, vector<vector<int>> &res){
        if(curr.size() == nums.size()){
            res.push_back(curr);
        }

        for(int i = 0; i < nums.size(); i++){
            if(visited.find(nums[i]) != visited.end()) continue;

            curr.push_back(nums[i]);
            visited.insert(nums[i]);
            dfs(nums, curr, visited, res);
            //backtracking
            curr.pop_back();
            visited.erase(nums[i]);
        }
    }
};
