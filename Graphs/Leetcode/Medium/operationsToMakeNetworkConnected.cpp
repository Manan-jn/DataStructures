//1319. Number of Operations to Make Network Connected
//Leetcode Medium Graphs

class Solution {
public:
    int findSet(int i,int*parent){
        if(parent[i]==-1){
            return i;
        }
        return findSet(parent[i],parent);
    }
    
    void union_set(int x,int y,int*parent,int &count){
        int s1 = findSet(x,parent);
        int s2 = findSet(y,parent);
        
        if(s1!=s2){
            parent[s2]=s1;
        }
        else{
            count++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int count =0;
        int *parent = new int[n];
        for(int i=0;i<n;i++){
            parent[i]=-1;
        }
        for(int i=0;i<connections.size();i++){
            union_set(connections[i][0],connections[i][1],parent,count);
        }
        int edge =0;
        for(int i=0;i<n;i++){
            if(parent[i]==-1){
                edge++;
            }
        }
        edge--;
        if(count>=edge){
            return edge;
        }
        return -1;
        
    }
};