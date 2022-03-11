//2192. All Ancestors of a Node in a Directed Acyclic Graph
//Leetcode Medium Graphs

class revGraph{
    public:
    int V;
    list<int>*li;
    
    revGraph(int v){
        this->V = v;
        li = new list<int>[V];
    }
    
    void addEdge(int i,int j){
        li[j].push_back(i);
    }
        
    vector<int> bfs(int node){
        vector<int>res;
        queue<int>q;
        bool*visited = new bool[V]{0};
        
        q.push(node);
        visited[node]=true;
        
        while(!q.empty()){
            int f = q.front();
            q.pop();
                         
            if(f!=node){
                res.push_back(f);
            }
    
            for(auto n: li[f]){
                if(!visited[n]){
                    visited[n]=true;
                    q.push(n);
                }
            }
       
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        revGraph rev(n);
        
        for(int i=0;i<edges.size();i++){
            rev.addEdge(edges[i][0],edges[i][1]);
        }
        vector<vector<int>>ans;
        
        for(int i=0;i<n;i++){
            vector<int>t = rev.bfs(i);
            sort(t.begin(),t.end());
            ans.push_back(t);
        }
        return ans;
    }
};