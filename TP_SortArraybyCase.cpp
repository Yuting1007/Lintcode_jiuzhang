class Solution {
public:
    /*
     * @param chars: The letter array you should sort by Case
     * @return: nothing
     */
    void sortLetters(string &letters) {
        // write your code here
        int i = 0;
        for (int j = 0; j < letters.size(); ++j)
        {
            if (letters[j] >= 'a' && letters[j] <= 'z')
            {
                swap(letters[i++], letters[j]);
            }
        }
    }
};
