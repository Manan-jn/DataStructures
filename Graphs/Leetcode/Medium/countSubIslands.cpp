//1905. Count Sub Islands
//Leetcode Medium Graphs

class Solution {
public:
    int m;
    int n;
    
    void dfs(int i,int j,vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        if(i<0 || i>m-1 || j<0 || j>n-1){
            return;
        }
        if(grid2[i][j]!=1){
            return;
        }
  
        grid2[i][j]=0;
        
        dfs(i+1,j,grid1,grid2);
        dfs(i-1,j,grid1,grid2);
        dfs(i,j+1,grid1,grid2);
        dfs(i,j-1,grid1,grid2);
        
        return;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid1.size();
        n = grid1[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j]==1 && grid1[i][j]==0){
                    dfs(i,j,grid1,grid2);
                }
            }
        }
        
        int count =0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j]==1){
                    count++;
                    dfs(i,j,grid1,grid2);
                }
            }
        }
        return count;
    }
};