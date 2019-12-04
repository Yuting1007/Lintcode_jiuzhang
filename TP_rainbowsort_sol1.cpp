class Solution {
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */
    void sortColors2(vector<int> &colors, int k) {
        // write your code here
        rainbowSort(colors, 0, colors.size() - 1, 1, k);
    }

private:
    void rainbowSort(vector<int> &colors, int start, int end, int colorfrom, int colorto){
        if(start == end || colorfrom == colorto){
            return;
        }

        int left = start;
        int right = end;
        int mid = colorfrom + (colorto - colorfrom) / 2;

        while(left <= right){
            while(left <= right && colors[left] <= mid){
                left++;
            }
            while(left <= right && colors[right] > mid){
                right--;
            }
            if(left <= right){
                swap(colors[left], colors[right]);
                left++;
                right--;
            }
        }

        rainbowSort(colors, start, right, colorfrom, mid);
        rainbowSort(colors, left, end, mid + 1, colorto);
    }


};
