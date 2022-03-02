//733. Flood Fill
//Leetcode Easy Graphs

class Solution {
public:
    int m;
    int n;
    
    void dfs(vector<vector<int>>& image,int i,int j,int newColor,int org){
        if(i<0 || i>n-1 || j<0 || j>m-1){
            return;
        }
        if(image[i][j]!=org ||image[i][j]==newColor){
            return;
        }
        image[i][j]= newColor;

        
        dfs(image,i+1,j,newColor,org);
        dfs(image,i-1,j,newColor,org);
        dfs(image,i,j+1,newColor,org);
        dfs(image,i,j-1,newColor,org);
        return;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        n = image.size();
        m = image[0].size();
        int org = image[sr][sc];

        dfs(image,sr,sc,newColor,org);
        
        return image;
    }
};