class Solution {
public:
    /*
     * @param A: An integer array
     * @param B: An integer array
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(vector<int> &A, vector<int> &B) {
        // write your code here
        const int n1 = A.size();
        const int n2 = B.size();
        //make sure that n1 <= n2
        if(n1 > n2) return findMedianSortedArrays(B, A);

        const int k = (n1 + n2 + 1) / 2;
        //binary search, find m1
        int l = 0;
        int r = n1;
        while(l<r){
            int m1 = l + (r - l)/2;
            int m2 = k - m1;
            if(A[m1] < B[m2- 1]){
                l = m1 + 1;
            } else {
                r = m1;
            }
        }

        const int m1 = l;
        const int m2 = k - l;

        //c1 = c(k-1)
        //c1 = max(A[m1-1], B[m2 - 1])
        const int c1 = max(m1 <= 0 ? INT_MIN : A[m1 - 1],
                           m2 <= 0 ? INT_MIN : B[m2 - 1]);
        //if odd
        if((n1 + n2) % 2 == 1) return c1;
        //if even
        //find c2 = ck = min(A[m1], B[m2])
        const int c2 = min(m1 >= n1 ? INT_MAX : A[m1],
                           m2 >= n2 ? INT_MAX : B[m2]);
        return (c1 + c2) * 0.5;
    }
};
