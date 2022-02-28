//547. Number of Provinces
//Leetcode Medium Graphs

class Solution {
public:
    int findSet(int i,int*parent){
        if(parent[i]==-1){
            return i;
        }
        return findSet(parent[i],parent);
    }
    void union_set(int x,int y,int*parent){
        int s1 = findSet(x,parent);
        int s2 = findSet(y,parent);
        if(s1!=s2){
            parent[s1]=s2;
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int*parent = new int[n];
        for(int i=0;i<n;i++){
            parent[i]=-1;
        }
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(i!=j && isConnected[i][j]==1){
                    union_set(i,j,parent);
                }
            }
        }
        int res =0;
        for(int i=0;i<n;i++){
            if(parent[i]==-1){
                res++;
            }
        }
        return res;
    }
};