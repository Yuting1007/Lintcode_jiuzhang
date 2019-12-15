//a new approach to start with a minheap
class Cell {
public:
    int row, col, val;
    //object
    Cell(int r, int c, int v): row(r), col(c), val(v){};
    //operator
    bool operator < (const Cell& C) const {
        return val > C.val;
    }
};

class Solution {
public:
    /**
     * @param arrays: k sorted integer arrays
     * @return: a sorted array
     */
    vector<int> mergekSortedArrays(vector<vector<int>> &arrays) {
        // write your code here
        vector<int> result;
        int m = arrays.size();//the number of arrays
        if(m == 0){
            return result;
        }

        priority_queue<Cell> pq;
        for(int i = 0; i < m; i++){
            if(arrays[i].size() != 0){
                pq.emplace(Cell(i, 0, arrays[i][0]));
            }
        }

        while(!pq.empty()){
            //get the smallerst
            Cell C = pq.top();
            //push into result
            result.push_back(C.val);
            pq.pop();
            //get the second in, if there is a second
            if(C.col < arrays[C.row].size() - 1){
                pq.emplace(Cell(C.row, C.col + 1, arrays[C.row][C.col + 1]));
            }
        }
        return result;
    }
};
