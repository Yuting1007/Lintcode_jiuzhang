class Solution {
public:
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        // write your code here
        //create a hashmap
        unordered_map <string, vector<string>> table;
        //sort the string
        for(string& str : strs){
            string mode = str;
            sort(mode.begin(), mode.end());
            table[mode].push_back(str);
        }

        vector<string> result;
        //iterate the table
        for(auto it = table.begin(); it != table.end(); ++it){
            if(it->second.size() > 1){
                for(string& s : it->second){
                    result.push_back(s);
                }
            }
        }
        return result;
    }
};
