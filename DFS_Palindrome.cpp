class Solution {
public:
    /*
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string &s) {
        // write your code here
        vector<vector<string>> ans;
        vector<string> curr;
        if(s.length() == 0){
            return ans;
        }

        dfs(s, curr, ans);
        return ans;
    }

private:

    void dfs(string &s, vector<string> &curr, vector<vector<string>> &ans){
        if(s.length() == 0){
            ans.push_back(curr);
            return;
        }

        for(int i = 0; i < s.length(); i++){
            string head = s.substr(0, i+1);
            if(!isPali(head)){
                continue;
            }
            curr.push_back(head);
            string tail = s.substr(i+1, s.length()-i-1);
            dfs(tail, curr, ans);
            curr.pop_back();
        }
    }

    bool isPali(string &s){
        for(int l = 0, r = s.size() - 1; l < r; l++, r--){
            if(s[l] != s[r]){
                return false;
            }
        }
        return true;
    }
};
