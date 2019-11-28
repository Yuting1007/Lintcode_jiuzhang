class Solution {
public:
    /**
     * @param numbers: An array of Integer
     * @param target: target = numbers[index1] + numbers[index2]
     * @return: [index1, index2] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &numbers, int target) {
        // write your code here
        vector<int> res(2);
        unordered_map<int, int> table;
        for(int i = 0; i < numbers.size(); i++){
            if(table.find(target - numbers[i]) != table.end()){
                res[0] = table[target - numbers[i]];
                res[1] = i;
                break;
            } else {
                table[numbers[i]] = i;
            }
        }
        return res;
    }
};
