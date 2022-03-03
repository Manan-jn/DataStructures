//785. Is Graph Bipartite?
//Leetcode Medium Graphs

class Graph{
    public:
    int V;
    list<int>*l;
    Graph(int v){
        this->V = v;
        l= new list<int>[V];
    }
    void addEdge(int i,int j){
        l[i].push_back(j);
    }
    
    bool dfsHelper(int i,int*color,int par){
        if(par==-1){
            color[i]=1;
        }
        else{
            color[i]= 1-color[par];
        }
        for(auto n: l[i]){
            if(color[n]==-1){
                bool t  = dfsHelper(n,color,i);
                if(t==false){
                    return false;
                }
            }
            else if(color[n]==color[i]){
                return false;
            }
        }
        return true;
    }
    bool dfs(){
        int*color = new int[V];
        for(int i=0;i<V;i++){
            color[i]=-1;
        }
        
        
        int flag=0;
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                bool t = dfsHelper(i,color,-1);
                if(t==false){
                    flag=1;
                    break;
                }
            }
        }
        if(flag==1){
            return false;
        }
        return true;
    }
};

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        Graph g(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                g.addEdge(i,graph[i][j]);
            }
        }
        return g.dfs();
    }
};