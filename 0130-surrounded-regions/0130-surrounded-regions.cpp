class Solution {
    private:
    void marksafe(int row,int col,vector<vector<char>>& board){
        int rows=board.size();
        int cols=board[0].size();
        if(row<0 || col<0 || row>=rows || col>=cols || board[row][col] !='O'){
            return;
        }
        board[row][col]='#';
        marksafe(row-1,col,board);
        marksafe(row+1,col,board);
        marksafe(row,col-1,board);
        marksafe(row,col+1,board);
    }
public:
    void solve(vector<vector<char>>& board) {
        int rows=board.size();
        int cols=board[0].size();
        for(int row=0;row<rows;row++){
            marksafe(row,0,board);
            marksafe(row,cols-1,board);
        }
        for(int col=0;col<cols;col++){
            marksafe(0,col,board);
            marksafe(rows-1,col,board);

        }
        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){
                if(board[row][col]=='O'){
                    board[row][col]='X';
                }
                if(board[row][col]=='#'){
                    board[row][col]='O';
                }
            }
        }
        
    }
};
void printboard(vector<vector<char>>& board){
    for(vector<char>& row:board){
        for(char cell: row){
            cout<<cell<<" ";
        }
    
    
    }
}
