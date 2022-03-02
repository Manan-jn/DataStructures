//695. Max Area of Island
//Leetcode Medium Graphs

class Solution {
public:
    int n =0;
    int m =0;
    
    void dfs(vector<vector<int>>&grid,int i,int j,int&count){
        if(i<0 || i>n-1 || j<0 || j>m-1){
            return;
        }
        if(grid[i][j]!=1){
            return;
        }
        grid[i][j]=0;
        count++;
    
        dfs(grid,i+1,j,count);
        dfs(grid,i-1,j,count);
        dfs(grid,i,j+1,count);
        dfs(grid,i,j-1,count);
        
        return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int count =0;
                    dfs(grid,i,j,count);
                    ans = max(ans,count);
                }
            }
        }
        return ans;
    }
};