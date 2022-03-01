//802. Find Eventual Safe States
//Leetcode Medium Graphs

class Graph{
    public:
    int V;
    list<int>*l;
    Graph(int v){
        this->V = v;
        l = new list<int>[V];
    }
    
    void addEdge(int i,int j){
        l[i].push_back(j);
    }
    
    void dfsHelper(int node,bool*visited,map<int,int>&mp,vector<int>&res){
        visited[node]=true;
        int count =0;
        
        for(auto n:l[node]){
            if(!visited[n]){
                dfsHelper(n,visited,mp,res);
            }
            if(mp.find(n)!=mp.end()){
                count++;
            }
        }
        
        if(count==l[node].size()){
            res.push_back(node);
            mp[node]++;
        }
        return;
    }
    
    vector<int> dfs(map<int,int>&mp){
        bool*visited = new bool[V]{0};
        vector<int>res;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfsHelper(i,visited,mp,res);
            }
        }
        return res;
    }
};
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        Graph g(graph.size());
        map<int,int>mp;
        
        for(int i=0;i<graph.size();i++){
            if(graph[i].size()==0){
                mp[i]++;
            }
            for(int j=0;j<graph[i].size();j++){
                g.addEdge(i,graph[i][j]);
            }
        }
        
        vector<int>res = g.dfs(mp);
        sort(res.begin(),res.end());
        
        return res;
    }
};