//1162. As Far from Land as Possible
//Leetcode Medium Graphs

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        queue<pair<int,int>>q;
        int n = grid.size();
        vector<vector<int>>distance(n,vector<int>(n,-1));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    distance[i][j]=0;
                }
            }
        }
        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            if(x+1<n  && distance[x+1][y]==-1){
                distance[x+1][y]= distance[x][y]+1;
                grid[x+1][y]=1;
                q.push({x+1,y});
            }
            if(x-1>=0 && distance[x-1][y]==-1){
                distance[x-1][y]= distance[x][y]+1;
                grid[x-1][y]=1;
                q.push({x-1,y});
            }
            if(y+1<n && distance[x][y+1]==-1){
                distance[x][y+1] = distance[x][y]+1;
                grid[x][y+1]=1;
                q.push({x,y+1});
            }
            if(y-1>=0 && distance[x][y-1]==-1){
                distance[x][y-1] = distance[x][y]+1;
                grid[x][y-1]=1;
                q.push({x,y-1});
            }
        }
        int ans =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans = max(ans,distance[i][j]);
            }
        }
        if(ans==0){
            return -1;
        }
        return ans;        
    }
};