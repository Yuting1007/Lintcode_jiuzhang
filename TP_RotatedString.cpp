class Solution {
public:
    /**
     * @param str: An array of char
     * @param offset: An integer
     * @return: nothing
     */
    void rotateString(string &str, int offset) {
        // write your code here
        if(str.size() == 0) return;
        offset = offset % str.size();
        str = str.substr(str.size() - offset, offset) + str.substr(0, str.size() - offset);
    }
};
