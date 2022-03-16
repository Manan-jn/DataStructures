//994. Rotting Oranges
//Leetcode Medium Graphs

class Solution {
public:
    int count =0;
    int n;
    int m;
    
    void bfs(vector<vector<int>>&grid,vector<vector<int>>&dis){

        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
               for(int j=0;j<m;j++){
                   if(grid[i][j]==2){
                       q.push({i,j});
                   }
               }
          }
        
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            //check for the neighbours of that node
            if(i+1<=n-1 && grid[i+1][j]==1){
                dis[i+1][j]=dis[i][j]+1;
                grid[i+1][j]=2;
                q.push({i+1,j});
            }
            if(i-1>=0 && grid[i-1][j]==1){
                dis[i-1][j]=dis[i][j]+1;
                grid[i-1][j]=2;
                q.push({i-1,j});
            }
            if(j+1<=m-1 && grid[i][j+1]==1){
                dis[i][j+1]=dis[i][j]+1;
                grid[i][j+1]=2;
                q.push({i,j+1});
            }
            if(j-1>=0 && grid[i][j-1]==1){
                dis[i][j-1]=dis[i][j]+1;
                grid[i][j-1]=2;
                q.push({i,j-1});
            }
        }
        return;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        //for every i,j element there will be four neighbours of that node , will create a adjancency list consisting of those neighbours and then will do a bfs on that graph with the visitied array
        //start the bfs from the first rotten one
        //if we find the neighbours of node as not rotten
        //increment count
        //make them rotten mark visited and push them inside the queue
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>>dis(n,vector<int>(m,0));
        
        bfs(grid,dis);
        
        int flag =1;
        int maxD= 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    flag = 0;
                    break;
                }
                maxD = max(maxD,dis[i][j]);   
            }
        }
        if(flag==0){
            return -1;
        }
        return maxD;
    }
};