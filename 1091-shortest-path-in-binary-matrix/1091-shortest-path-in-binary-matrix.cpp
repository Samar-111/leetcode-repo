class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        pair<int,int> source = {0,0};
        pair<int,int> destination = {rows-1,cols-1};

     
        if(grid[0][0] == 1 || grid[rows-1][cols-1] == 1) {
            return -1;
        }

        
        if(source == destination) {
            return 1;
        }

        vector<vector<int>> dist(rows, vector<int>(cols, -1));

        queue<pair<int,int>> q;

        dist[0][0] = 1;
        q.push(source);

        
        int drow[8] = {-1,-1,-1,0,0,1,1,1};
        int dcol[8] = {-1,0,1,-1,1,-1,0,1};

        while(!q.empty()) {

            auto [row,col] = q.front();
            q.pop();

            for(int direction = 0; direction < 8; direction++) {

                int nextrow = row + drow[direction];
                int nextcol = col + dcol[direction];

              
                if(nextrow < 0 || nextrow >= rows ||
                   nextcol < 0 || nextcol >= cols) {
                    continue;
                }

             
                if(grid[nextrow][nextcol] == 1 ||
                   dist[nextrow][nextcol] != -1) {
                    continue;
                }

                int nextdistance = dist[row][col] + 1;

                dist[nextrow][nextcol] = nextdistance;

                if(nextrow == destination.first &&
                   nextcol == destination.second) {
                    return nextdistance;
                }

                q.push({nextrow,nextcol});
            }
        }

        return -1;
    }
};