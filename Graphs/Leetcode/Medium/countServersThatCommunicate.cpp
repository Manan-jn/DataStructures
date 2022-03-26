//1267. Count Servers that Communicate
//Leetcode Medium Graphs

class Solution {
public:
    int m;
    int n;
    
    void dfs(int i,int j,vector<vector<int>>&grid,int&count){
        if(grid[i][j]==1){
            grid[i][j]=0;
            count++;
        }
        for(int k=0;k<n;k++){
            if(grid[i][k]==1 && k!=j){
                count++;
                grid[i][k]=0;
                dfs(i,k,grid,count);
            }
        }
        for(int k=0;k<m;k++){
            if(grid[k][j]==1 && k!=i){
                count++;
                grid[k][j]=0;
                dfs(k,j,grid,count);
            }
        }
    }
    
    int countServers(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        int ans =0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int count =0;
                    dfs(i,j,grid,count);
                    if(count>1){
                        ans+=count;
                    }
                }
            }
        }
        return ans;
    }
};