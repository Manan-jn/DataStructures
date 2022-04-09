//934. Shortest Bridge
//Leetcode Medium Graphs

class Solution {
public:
    int m;
    int n;
    
    queue<pair<pair<int,int>,int>>q;
    
    void dfs(vector<vector<int>>&grid,int i,int j,int count,vector<vector<int>>&vis){
        if(i<0 || i>m-1 || j<0 ||j>n-1){
            return;
        }
        if(grid[i][j]==0 || vis[i][j]==1){
            return;
        }
        
        vis[i][j]=1;
        q.push({{i,j},0});
        grid[i][j]=count;
        
        dfs(grid,i+1,j,count,vis);
        dfs(grid,i-1,j,count,vis);
        dfs(grid,i,j+1,count,vis);
        dfs(grid,i,j-1,count,vis);
        
        return;
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        int count =0;
        
        vector<vector<int>>vis(m,vector<int>(n,0));
        
        int flag =0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
    
                if(grid[i][j]==1 && vis[i][j]!=1){
                    flag =1;
                    dfs(grid,i,j,count,vis);
                    break;
                }
            }
            if(flag ==1){
                break;
            }
        }
        
        int dist =-1;
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int c = q.front().second;
            
            q.pop();
            
            if(x+1<=m-1 && vis[x+1][y]!=1){
                if(grid[x+1][y]==1){
                    dist = c;
                    break;
                }
                else{
                    vis[x+1][y]=1;
                    q.push({{x+1,y},c+1});
                }
            }
            if(x-1>=0 && vis[x-1][y]!=1){
                if(grid[x-1][y]==1){
                    dist = c;
                    break;
                }
                else{
                    vis[x-1][y]=1;
                    q.push({{x-1,y},c+1});
                }   
            }
            if(y-1>=0 && vis[x][y-1]!=1){
                if(grid[x][y-1]==1){
                    dist = c;
                    break;
                }
                else{
                    vis[x][y-1]=1;
                    q.push({{x,y-1},c+1});
                }   
            }
            if(y+1<=n-1 && vis[x][y+1]!=1){
                if(grid[x][y+1]==1){
                    dist = c;
                    break;
                }
                else{
                    vis[x][y+1]=1;
                    q.push({{x,y+1},c+1});
                }   
            }
        }
        return dist;      
    }
};