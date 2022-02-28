//797. All Paths From Source to Target
// Leetcode Medium Graphs

class Graph{
    public:
    int V;
    list<int>*l;
    Graph(int v){
        this->V = v;
        l = new list<int>[v];
    }
    void addEdge(int i,int j){
        l[i].push_back(j);
    }
    
    void dfsHelper(int node,bool*visited,vector<int>&temp,vector<vector<int>>&res){
        visited[node]=true;
        temp.push_back(node);
        
        for(auto n:l[node]){
            if(!visited[n]){
                dfsHelper(n,visited,temp,res);
            }
        }
        if(node==V-1){
            res.push_back(temp);
        }
        temp.pop_back();
        visited[node]= false;
        return;
    }
    vector<vector<int>> dfs(){
        bool*visited = new bool[V]{0};
        vector<vector<int>>res;
        vector<int>temp;
        
        dfsHelper(0,visited,temp,res);
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        Graph g(n);
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                g.addEdge(i,graph[i][j]);
            }
        }
        return g.dfs();
    }
};