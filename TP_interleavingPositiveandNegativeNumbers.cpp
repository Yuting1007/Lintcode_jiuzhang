class Solution {
public:
    /*
     * @param A: An integer array.
     * @return: nothing
     */
    void rerange(vector<int> &A) {
        // write your code here
        if(A.size() == 0) return;
        //count the number of positive and negative numbers
        int posNum = 0;
        int negNum = 0;
        for(int num : A){
            if(num >= 0){
                posNum++;
            } else {
                negNum++;
            }
        }
         int pos = (posNum >= negNum) ? 0 : 1;
         int neg = 1 - pos;

         while(pos < A.size() && neg < A.size()){
             //move to the last satified position
             while(pos < A.size() && A[pos] >= 0){
                 //move
                 pos += 2;
             }
             while(neg < A.size() && A[neg] < 0){
                 neg += 2;
             }
             //reach the swap position
             //swap
             if(pos < A.size() && neg < A.size()){
                swap(A[pos], A[neg]);
                //move
                pos += 2;
                neg += 2;
             }
         }
    }
};
