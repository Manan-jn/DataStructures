//417. Pacific Atlantic Water Flow
//Leetcode Medium Graphs

class Solution {
public:
    int m;
    int n;
    
    void dfs(int i,int j,vector<vector<int>>&heights,int org,vector<vector<int>>&curr){
        if(i<0 || i>m-1 || j<0 || j>n-1){
            return;
        }
        if(heights[i][j]<org || curr[i][j]==1){
            return;
        }
        curr[i][j]=1;
        
        dfs(i-1,j,heights,heights[i][j],curr);
        dfs(i,j+1,heights,heights[i][j],curr);
        dfs(i+1,j,heights,heights[i][j],curr);
        dfs(i,j-1,heights,heights[i][j],curr);
        return;
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        
        vector<vector<int>>pacific(m,vector<int>(n,0));
        vector<vector<int>>atlantic(m,vector<int>(n,0));
        
        vector<vector<int>>ocean;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0){
                    //means we can go to pacific from here
                    dfs(i,j,heights,heights[i][j],pacific);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==m-1 || j==n-1){
                    //means we can go to atlantic from here
                    dfs(i,j,heights,heights[i][j],atlantic);
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j]==1 && atlantic[i][j]==1){
                   vector<int>res;
                    res.push_back(i);
                    res.push_back(j);
                    ocean.push_back(res);
                }
            }
        }

        return ocean;
    }
};