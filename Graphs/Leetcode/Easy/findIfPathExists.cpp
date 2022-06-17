//Easy
//1971. Find if Path Exists in Graph

class Solution {
public:
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
        
        bool bfs(int src,int dest){
            queue<int>q;
            bool*visited = new bool[V]{0};
            q.push(src);
            visited[src]= true;
            bool ans = false;
            
            while(!q.empty()){
                int f = q.front();
                
                q.pop();
                
                if(f==dest){
                    ans = true;
                    break;
                }
                
                for(auto n:l[f]){
                    if(!visited[n]){
                        visited[n]= true;
                        q.push(n);
                    }
                }
            }
            return ans;
        }
        
    };
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        Graph g(n);
        
        for(int i=0;i<edges.size();i++){
            g.addEdge(edges[i][0],edges[i][1]);
        }
        
        return g.bfs(source,destination);
    }
};