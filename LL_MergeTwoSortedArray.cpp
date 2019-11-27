class Solution {
public:
    /**
     * @param A: sorted integer array A
     * @param B: sorted integer array B
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        // write your code here
        int i = 0;
        int j = 0;
        vector<int> res;

        while(i < A.size() && j < B.size()){
            if(A[i] < B[j]){
                res.push_back(A[i]);
                i++;
            } else {
                res.push_back(B[j]);
                j++;
            }
        }

        while(i < A.size()){
            res.push_back(A[i++]);
        }
        while(j < B.size()){
            res.push_back(B[j++]);
        }

        return res;
    }
};
