class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target: An integer
     * @return: A list of lists of integers
     */
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        // write your code here
        vector<vector<int>> ans;
        vector<int> curr;
        std::sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, curr, ans);
        return ans;
    }

private:
    void dfs(vector<int> &candidates, int target, int index, vector<int> &curr, vector<vector<int>> &ans){
        if(target < 0){
            return;
        }

        if(target == 0){
            ans.push_back(curr);
            return;
        }

        for(int i = index; i < candidates.size(); i++){
            //skip dulpicates
            if(i > index && candidates[i] == candidates[i - 1]){
                continue;
            }

            if(candidates[i] > target){
                break;
            }
            //dfs and backtracking
            curr.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i, curr, ans);
            curr.pop_back();
        }
    }

};
