//1615. Maximal Network Rank
//Leetcode Medium Graphs

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>>network(n,vector<int>(n,0));
        
        for(int i=0;i<roads.size();i++){
            network[roads[i][0]][roads[i][1]]=1;
            network[roads[i][1]][roads[i][0]]=1;
        }
        
        vector<int>track;
        
        for(int i=0;i<n;i++){
            int count =0;
            for(int j=0;j<n;j++){
                if(network[i][j]==1){
                    count++;
                }
            }
            track.push_back(count);
        }
        
        int ans = INT_MIN;
        
        for(int i=0;i<n;i++){
            int s = track[i];
            
            for(int j=i+1;j<n;j++){
                int e = track[j];
                
                if(network[i][j]==1){
                    e--;
                }
                ans = max(ans,s+e);
            }
        }
        return ans;
    }
};