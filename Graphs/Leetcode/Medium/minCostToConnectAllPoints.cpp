//1584. Min Cost to Connect All Points
//Leetcode Medium Graphs

class DSU{
    int*parent;
    int*rank;
    
    public:
    DSU(int n){
        parent = new int[n];
        rank = new int[n];
        for(int i=0;i<n;i++){
            parent[i]=-1;
            rank[i]=1;
        }
    }
    
    int find(int i){
        if(parent[i]==-1){
            return i;
        }
        return parent[i]= find(parent[i]);
    }
    
    void unite(int x,int y){
        int s1 = find(x);
        int s2 = find(y);
        if(s1!=s2){
            if(rank[s1]<rank[s2]){
                parent[s1]=s2;
                rank[s2]+=rank[s1];
            }
            else{
                parent[s2]=s1;
                rank[s1]+=rank[s2];
            }
        }
    }
};

class graph{
    vector<pair<int,pair<int,int>>>edgeList;
    int V;
    
    public:
    graph(int v){
        this->V =v;
    }
    void addEdge(int x,int y,int wt){
        edgeList.push_back({wt,{x,y}});
    }
    int kruksal(){
        sort(edgeList.begin(),edgeList.end());
            DSU s(V);
            int ans= 0;
        for(auto edge: edgeList){
            int w = edge.first;
            int x = edge.second.first;
            int y = edge.second.second;
            if(s.find(x)!=s.find(y)){
                s.unite(x,y);
                ans+=w;
            }   
        }
        return ans;
        }
    };


class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        graph g(n);
        
        for(int i=0;i<points.size()-1;i++){
            
            int x1 = points[i][0];
            int y1 = points[i][1];
                
            for(int j=i+1;j<points.size();j++){
                int x22 = points[j][0];
                int y22 = points[j][1];
                if(j!=i){    
                    int dist = abs(x1-x22) + abs(y1-y22);
                    g.addEdge(i,j,dist);   
                }
            }
     
        }
        return g.kruksal();
    }
};