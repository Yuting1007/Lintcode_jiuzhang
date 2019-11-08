// Given a boolean 2D matrix, 0 is represented as the sea, 1 is represented as the island.
// If two 1 is adjacent, we consider them in the same island.
// We only consider up/down/left/right adjacent.
class Solution {
public:
    /**
     * @param grid: a boolean 2D matrix
     * @return: an integer
     */
    int numIslands(vector<vector<bool>> &grid) {
        // write your code here
        if(grid.empty()) return 0;
        //get the nrow and ncol
        int nrow = grid.size();
        int ncol = grid[0].size();
        int ans = 0;
        //traverse
        for(int x = 0; x < nrow; x++){
            for(int y = 0; y < ncol; y++){
                if(grid[x][y] == true){
                    ans += 1;
                }
                dfs(grid, x, y, nrow, ncol);
            }
        }
        return ans;
    }

private:
    void dfs(vector<vector<bool>> &grid, int x, int y, int nrow, int ncol){
        //out of bound
        // if (x < 0 || y < 0 || x >= nrow || y >= ncol || grid[x][y] = false){
        //     return;
        // }
        if (x < 0 || x >= nrow) return;
        if (y < 0 || y >= ncol) return;
        if (!grid[x][y]) return;
        grid[x][y] = false;
        dfs(grid, x+1, y, nrow, ncol);
        dfs(grid, x-1, y, nrow, ncol);
        dfs(grid, x, y+1, nrow, ncol);
        dfs(grid, x, y-1, nrow, ncol);
    }
};
