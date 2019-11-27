class Solution {
public:
    /**
     * @param nums1: an integer array
     * @param nums2: an integer array
     * @return: an integer array
     */
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        // write your code here
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        unordered_set<int> l1(nums1.begin(), nums1.end());
        vector<int> ans;
        for(int num : nums2){
            if(l1.count(num) == 0) continue;
            ans.push_back(num);
            l1.erase(num);
        }
        std::unique(ans.begin(), ans.end());
        return ans;
    }
};
