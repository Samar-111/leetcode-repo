class Solution {
    void dfs(vector<vector<int>>& image, int r,int c, int originalcolor,int newcolor){
        int m=image.size();
        int n=image[0].size();
        if(r<0||c<0||r>=m||c>=n){
            return;
        }
        if(image[r][c]!=originalcolor)
        return;
        image[r][c]=newcolor;
        dfs(image,r-1,c,originalcolor,newcolor);
        dfs(image,r+1,c,originalcolor,newcolor);
        dfs(image,r,c-1,originalcolor,newcolor);
        dfs(image,r,c+1,originalcolor,newcolor);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalcolor=image[sr][sc];
        if(originalcolor==color)
        return image;
        dfs(image,sr,sc,originalcolor,color);
        return image;
    }
};