class Solution {
public:
    /**
     * @param num: Given the candidate numbers
     * @param target: Given the target number
     * @return: All the combinations that sum to target
     */
    vector<vector<int>> combinationSum2(vector<int> &num, int target) {
        // write your code here
        vector<vector<int>> ans;
        vector<int> curr;
        std::sort(num.begin(), num.end());
        dfs(num, target, 0, curr, ans);
        return ans;
    }

private:
    void dfs(vector<int> &candidates, int target, int index, vector<int> &curr, vector<vector<int>> &ans){
        if(target < 0){
            return;
        }
        //find it
        if(target == 0){
            ans.push_back(curr);
            return;
        }

        for(int i = index; i < candidates.size(); i++){
            if(candidates[i] > target){
                return;
            }
            //skip dulpicates
            if(i > index && candidates[i] == candidates[i - 1]){
                continue;
            }
            //dfs and backtracking
            curr.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i + 1, curr, ans);
            curr.pop_back();
        }
    }
};
