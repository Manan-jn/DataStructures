//1091. Shortest Path in Binary Matrix
//Leetcode Medium Graphs

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0){
            return -1;
        }
        if(n==1){
            if(grid[n-1][n-1]==0){
                return 1;
            }
            else{
                return -1;
            }
        }
        
        queue<pair<int,int>>q;
        q.push({0,0});
        vector<vector<int>>dis(n,vector<int>(n,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dis[i][j]=-1;
                }
            }
        }
        
        dis[0][0]=1;
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;

            q.pop();
            
            if(i+1<=n-1 && j+1<=n-1 && grid[i+1][j+1]==0 && dis[i+1][j+1]==0){
                dis[i+1][j+1]= dis[i][j]+1;
                q.push({i+1,j+1});
            }
            if(i+1<=n-1 && j-1>=0 && grid[i+1][j-1]==0 && dis[i+1][j-1]==0){
                dis[i+1][j-1]= dis[i][j]+1;
                q.push({i+1,j-1});
            }
            if(i-1>=0 && j-1>=0 && grid[i-1][j-1]==0 && dis[i-1][j-1]==0){
                dis[i-1][j-1]= dis[i][j]+1;
                q.push({i-1,j-1});
            }
            if(i-1>=0 && j+1<=n-1 && grid[i-1][j+1]==0 && dis[i-1][j+1]==0){
                dis[i-1][j+1] = dis[i][j]+1;
                q.push({i-1,j+1});
            }
            if(i+1<=n-1 && grid[i+1][j]==0 && dis[i+1][j]==0){
                dis[i+1][j]= dis[i][j]+1;
                q.push({i+1,j});
            }
            if(j+1<=n-1 && grid[i][j+1]==0 && dis[i][j+1]==0){
                dis[i][j+1]= dis[i][j]+1;
                q.push({i,j+1});
            }
            if(j-1>=0 && grid[i][j-1]==0 && dis[i][j-1]==0){
                dis[i][j-1]= dis[i][j]+1;
                q.push({i,j-1});
            }
            if(i-1>=0 && grid[i-1][j]==0 && dis[i-1][j]==0){
                dis[i-1][j]= dis[i][j]+1;
                q.push({i-1,j});
            }
        }

        if(dis[n-1][n-1]==0){
            return -1;
        }
        return dis[n-1][n-1];
    }
};