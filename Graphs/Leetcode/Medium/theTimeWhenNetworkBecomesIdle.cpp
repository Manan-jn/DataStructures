//2039. The Time When the Network Becomes Idle
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
    int bfs(vector<int>& patience){
        int*distance = new int[V];
        for(int i=0;i<V;i++){
            distance[i]=INT_MAX;
        }
        distance[0]=0;   
        
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int f = q.front();
            q.pop();
            
            for(auto n: l[f]){
                if(distance[n]==INT_MAX){
                    distance[n] = distance[f]+1;
                    q.push(n);
                }
            }
        }

        int cur= 0;
        for(int i=1;i<V;i++){
            int dist = distance[i];
            int time = 2*dist;
            int wait = ((time - 1)/patience[i])*patience[i];
            cur = max(cur,time+wait);
         
        }
        return cur+1;
    }
};

class Solution {
public:
    
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        Graph g(n);
        for(int i=0;i<edges.size();i++){
            g.addEdge(edges[i][0],edges[i][1]);
        }
        return g.bfs(patience);
    }
};