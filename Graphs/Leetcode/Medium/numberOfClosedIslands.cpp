//1254. Number of Closed Islands
//Leetcode Medium Graphs

class Solution {
public:
    int n;
    int m;
    void dfs(vector<vector<int>>&grid,int i,int j){
        if(i<0 || i>n-1 || j<0 || j>m-1){
            return;
        }
        if(grid[i][j]!=0){
            return;
        }
        grid[i][j]=1;
        
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
        
        return;
    }
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int count =0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 && (i==0 || i==n-1 || j==0 || j==m-1)){
                    dfs(grid,i,j);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    count++;
                    dfs(grid,i,j);   
                }
            }
        }

        return count;
    }
};