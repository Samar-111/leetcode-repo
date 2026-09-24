class Solution {
    void dfs(int row, int col, vector<vector<int>>& grid){
        int rows=grid.size();
        int cols=grid[0].size();
        if(row>=rows || col>=cols || row<0 || col<0 || grid[row][col]==0){
            return;
        }
        grid[row][col]=0;
        dfs(row-1,col,grid);
        dfs(row+1,col,grid);
        dfs(row,col-1,grid);
        dfs(row,col+1,grid);

    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        for(int row=0;row<rows;row++){
            dfs(row,0,grid);
            dfs(row,cols-1,grid);
        }
        for(int col=0;col<cols;col++){
            dfs(0,col,grid);
            dfs(rows-1,col,grid);
        }
        int enclave=0;
        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){
                
                    enclave+=grid[row][col];
                
            }
        }
        return enclave;

        
    }
};