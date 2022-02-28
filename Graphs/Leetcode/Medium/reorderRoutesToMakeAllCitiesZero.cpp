//1466. Reorder Routes to Make All Paths Lead to the City Zero
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
        l[j].push_back(i);
    }
    int bfs(map<int,list<int>>&mp){
        bool *visited = new bool[V]{0};
        queue<int>q;
        
        q.push(0);
        visited[0]= true;
        int count =0;
        
        while(!q.empty()){
            int f = q.front();
            visited[f] = true;
            q.pop();
            
            for(auto n:l[f]){
                if(!visited[n]){
                    
                    if(mp.find(f)!=mp.end()){
                        list<int>nbrs = mp[f];
                        
                        for(auto it = nbrs.begin();it!=nbrs.end();it++){
                            if((*it)==n){
                                count++;
                            }
                        }
                    }
                    
                    q.push(n);
                }
            }
        }
        return count;
    }
};

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        map<int,list<int>>mp;
        Graph g(n);
        for(int i=0;i<connections.size();i++){
            g.addEdge(connections[i][0],connections[i][1]);
            mp[connections[i][0]].push_back(connections[i][1]);
        }
    
        return g.bfs(mp);
    }
};