//1462. Course Schedule IV
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
    }
    
    void bfs(vector<vector<int>>&queries,vector<bool>&res){
        vector<vector<int>>vis(V, vector<int>(V,0));
        vector<vector<int>>track(V,vector<int>(V,0));
        
        for(int i=0;i<V;i++){
            queue<int>q;
            q.push(i);
            while(!q.empty()){
                int f = q.front();
                q.pop();
                for(auto n: l[f]){
                    if(track[i][n]==0){
                        vis[i][n]=1;
                        track[i][n]=1;
                        q.push(n);
                    }
                    else{
                        continue;
                    }
                }
            }
        }

        for(int i=0;i<queries.size();i++){
            int s = queries[i][0];
            int e = queries[i][1];
            if(vis[s][e]==1){
                res.push_back(true);
            }
            else{
                res.push_back(false);
            }
        }
    }
};
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        Graph g(numCourses);
        
        for(int i=0;i<prerequisites.size();i++){
            g.addEdge(prerequisites[i][0],prerequisites[i][1]);
        }
        
        vector<bool>res;
        
        if(prerequisites.size()!=0){
            g.bfs(queries,res);
        }
        else{
            for(int i=0;i<numCourses;i++){
                res.push_back(false);
            }
        }
        return res;
    }
};