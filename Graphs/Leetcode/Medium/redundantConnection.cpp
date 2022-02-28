//684. Redundant Connection
//Leetcode Medium Graphs

class Solution {
public:
    int findSet(int i,int*parent){
        if(parent[i]==-1){
            return i;
        }
        return findSet(parent[i],parent);
    }
    void union_set(int x,int y,int*parent,vector<int>&res){
        int s1 = findSet(x,parent);
        int s2 = findSet(y,parent);
        if(s1!=s2){
            parent[s1]=s2;
        }
        else if(s1==s2){
            res.push_back(x);
            res.push_back(y);
        }
        return;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        int*parent = new int[n+1];
        for(int i=0;i<edges.size()+1;i++){
            parent[i]=-1;
        }
        vector<int>res;
        for(int i=0;i<edges.size();i++){
            union_set(edges[i][0],edges[i][1],parent,res);
        }
        return res;
    }
};