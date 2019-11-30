class Solution {
public:
    /**
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> &S) {
        // write your code here
        if(S.size() < 3) return 0;
        //sort in descending order
        sort(S.rbegin(), S.rend());

        int count = 0;
        for(int c = 0; c < S.size() - 2; c++){
            int a = S.size() - 1;
            int b = c + 1;
            while(a > b){
                if(S[a] + S[b] > S[c]){
                    count += a - b;
                    ++b;
                } else {
                    --a;
                }
            }
        }
        return count;
    }
};
