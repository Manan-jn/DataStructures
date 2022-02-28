//947. Most Stones Removed with Same Row or Column
//Leetcode Medium graphs

class Solution {
public:
    int findSet(int i,int*parent){
        if(parent[i]==-1){
            return i;
        }
        return parent[i]= findSet(parent[i],parent);
    }
    void union_set(int x,int y,int*parent,int*rank){
        int s1 = findSet(x,parent);
        int s2 = findSet(y,parent);
        if(s1!=s2){
            if(rank[s1]<rank[s2]){
                parent[s1]= s2;
                rank[s2]+=rank[s1];
            }
            else{
                parent[s2]= s1;
                rank[s1]+=rank[s2];
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        
        int*parent = new int[n];
        int*rank = new int[n];
        for(int i=0;i<n;i++){
            parent[i]=-1;
            rank[i]=1;
        }
        
        map<int,int>row;
        map<int,int>col;
        
        for(int i=0;i<stones.size();i++){
            if(row.find(stones[i][0])!=row.end()){
                int t = row[stones[i][0]];
                union_set(i,t,parent,rank);
            }
            if(col.find(stones[i][1])!=col.end()){
                int t = col[stones[i][1]];
                union_set(i,t,parent,rank);
            }
            row[stones[i][0]]=i;
            col[stones[i][1]]=i;
        }
        int ans =0;
        for(int i=0;i<n;i++){
            if(parent[i]==-1){
                ans++;
            }
        }
        
        return n-ans;
    }
};