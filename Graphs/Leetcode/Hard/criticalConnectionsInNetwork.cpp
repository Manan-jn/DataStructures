//1192. Critical Connections in a Network
//Leetcode Hard Graphs
//Find Bridges in Graph

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
    void dfsHelper(int u,bool*visited,int*disc,int*low,int*parent,int &timer,vector<vector<int>>&res){
        visited[u]= true;
        disc[u]= low[u]= timer;
        timer++;
        
        for(auto n: l[u]){
            if(!visited[n]){
                parent[n] = u;
                dfsHelper(n,visited,disc,low,parent,timer,res);
                low[u]= min(low[u],low[n]);
               
                if(low[n]>disc[u]){
                    vector<int>temp;
                    temp.push_back(u);
                    temp.push_back(n);
                    res.push_back(temp);
                }
            }
            else if(n!=parent[u]){
                low[u]= min(low[u],disc[n]);
            }
        }
    }
    vector<vector<int>> dfs(){
        bool*visited = new bool[V]{0};
        int*disc = new int[V];
        int*low = new int[V];
        int*parent = new int[V];
        
        for(int i=0;i<V;i++){
            disc[i]=low[i]=0;
            parent[i]=-1;
        }
        
        vector<vector<int>>res;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                int timer = 1;
                dfsHelper(i,visited,disc,low,parent,timer,res);
            }
        }
        return res;
    }
};


class Solution {
public:
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        Graph g(n);
        for(int i=0;i<connections.size();i++){
            g.addEdge(connections[i][0],connections[i][1]);
        }
        return g.dfs();
        
    }
};