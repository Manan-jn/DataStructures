//1926. Nearest Exit from Entrance in Maze
//Leetcode Medium Graphs

class Solution {
public:
    int m;
    int n;
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        m = maze.size();
        n = maze[0].size();
        
        queue<pair<int,int>>q;
        int sx = entrance[0];
        int sy = entrance[1];
        
        vector<vector<int>>dist(m,vector<int>(n,0));
        vector<vector<int>>vis(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(maze[i][j]=='+'){
                    dist[i][j]=-1;
                }
            }
        }
        
        q.push({sx,sy});
        vis[sx][sy]=1;
    
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            
            q.pop();
            
            if(x+1<=m-1 && maze[x+1][y]=='.' && vis[x+1][y]==0){
                vis[x+1][y]=1;
                dist[x+1][y]= dist[x][y]+1;
                q.push({x+1,y});
            }
            if(x-1>=0 && maze[x-1][y]=='.' && vis[x-1][y]==0){
                vis[x-1][y]=1;
                dist[x-1][y]= dist[x][y]+1;
                q.push({x-1,y});
            }
            if(y+1<=n-1 && maze[x][y+1]=='.' && vis[x][y+1]==0){
                vis[x][y+1]=1;
                dist[x][y+1]= dist[x][y]+1;
                q.push({x,y+1});
            }
            if(y-1>=0 && maze[x][y-1]=='.' && vis[x][y-1]==0){
                vis[x][y-1]=1;
                dist[x][y-1]= dist[x][y]+1;
                q.push({x,y-1});
            }
        }
        int ans = INT_MAX;
            
        for(int i=0;i<m;i++){
            if(dist[i][0]>0){
                ans = min(ans,dist[i][0]);
            }
            if(dist[i][n-1]>0){
                ans = min(ans,dist[i][n-1]);
            }
        }
        for(int i=0;i<n;i++){
            if(dist[0][i]>0){
                ans = min(ans,dist[0][i]);
            }
            if(dist[m-1][i]>0){
                ans = min(ans,dist[m-1][i]);
            }
        }
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
        
    }
};