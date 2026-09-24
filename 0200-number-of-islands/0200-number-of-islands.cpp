class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        if(row < 0 || col < 0 || row >= rows || col >= cols ||
           grid[row][col] == '0') {
            return;
        }

        grid[row][col] = '0';

        dfs(row - 1, col, grid); 
        dfs(row + 1, col, grid); 
        dfs(row, col - 1, grid); 
        dfs(row, col + 1, grid); 
    }

public:
    int numIslands(vector<vector<char>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        for(int row = 0; row < rows; row++) {
            for(int col = 0; col < cols; col++) {

                if(grid[row][col] == '1') {
                    count++;
                    dfs(row, col, grid);
                }
            }
        }

        return count;
    }
};