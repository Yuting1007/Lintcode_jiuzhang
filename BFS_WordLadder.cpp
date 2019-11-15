class Solution {
public:
    /*
     * @param start: a string
     * @param end: a string
     * @param dict: a set of string
     * @return: An integer
     */
    int ladderLength(string &start, string &end, unordered_set<string> &dict) {
        // write your code here
        //if end is not in the dict
        if(!dict.count(end)){
            dict.insert(end);//modified here
        };

        queue<string> q;
        q.push(start);

        int l = start.length();
        int step = 0;

        while(!q.empty()){
            step+=1;
            //level search
            for (int size = q.size(); size > 0; size--){
                string w = q.front();
                q.pop();
                //change every position in the word
                for(int i = 0; i < l; i++){
                    char ch = w[i];
                    for(int j = 'a'; j <= 'z'; j++){
                        w[i] = j;
                        //found the solution
                        if( w == end) return step + 1;
                        //not in the dict, skip
                        if(!dict.count(w)) continue;
                        //remove new word from the dict
                        dict.erase(w);
                        q.push(w);
                    }
                    //backtracking, to the i + 1 position
                    w[i] = ch;
                }
            }
        }
        return 0;
    }
};
