class Solution {
public:
    /**
     * @param n: An integer
     * @return: return a  integer as description.
     */
    int nthUglyNumber(int n) {
        // write your code here
        vector<int> ugly(n, 1);
        int i2 = 0, i3 = 0, i5 = 0;
        //we have set the ugly[0] = 1
        //start with 1
        for(int i = 1; i < n; i++){
            ugly[i] = min(ugly[i2] * 2, min(ugly[i3] * 3, ugly[i5] * 5));//modified here, only two atrributes in min()
            if(ugly[i2] * 2 == ugly[i]){
                i2++;
            }
            if(ugly[i3] * 3 == ugly[i]){
                i3++;
            }
            if(ugly[i5] * 5 == ugly[i]){
                i5++;
            }
        }
        return ugly[n-1];
    }
};
