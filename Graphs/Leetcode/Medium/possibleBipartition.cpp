//886. Possible Bipartition
//Leetcode Medium Graphs

class Graph{
    public:
    int V;
    list<int>*l;
    Graph(int v){
        this->V = v;
        l = new list<int>[V];
    }
    void addEdge(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    
    bool bipartite(int node,int*color){
        
        queue<int>q;
        q.push(node);
        color[node]=1;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it: l[node]){
                if(color[it]==-1){
                    color[it]=1-color[node];
                    q.push(it);
                }
                else if(color[it]==color[node]){
                    return false;
                }
            }
        }
        return true;
    }
    bool bfs(){
        int*color = new int[V];
        for(int i=0;i<V;i++){
            color[i]=-1;
        }
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(!bipartite(i,color)){
                    return false;
                }
            }
        }
        return true;
    }

};
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        Graph g(n);
        for(int i=0;i<dislikes.size();i++){
            g.addEdge(dislikes[i][0]-1,dislikes[i][1]-1);
        }
        return g.bfs();
    }
};