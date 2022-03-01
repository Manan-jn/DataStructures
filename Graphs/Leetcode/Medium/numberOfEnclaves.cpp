//1020. Number of Enclaves
//Leetcode Medium Graphs

class Solution {
public:
    int n=0;
    int m=0;
    void dfs(vector<vector<int>>&grid,int i,int j,int&count,int&flag){
        if(i<0 || i>n-1 || j<0 || j>m-1){
            return;
        }
     
        if(grid[i][j]!=1){
            return;
        }
        
        if(grid[i][j]==1 && (i==0 || i==n-1 || j==0 || j==m-1)){
            count=0;
            flag=1;
            return;
        }
        else{
            grid[i][j]=0;
            if(flag!=1){
                count++;
            }
        }
        dfs(grid,i+1,j,count,flag);
        dfs(grid,i-1,j,count,flag);
        dfs(grid,i,j+1,count,flag);
        dfs(grid,i,j-1,count,flag);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int res =0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i!=0 && i!=n-1 && j!=0 && j!=m-1){
                    if(grid[i][j]==1){
                        int count=0;
                        int flag=0;
                        dfs(grid,i,j,count,flag);
                        res+=count;
                    }
                }
            }
        }
 
        return res;
    }
};