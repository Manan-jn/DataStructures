//Easy
//1791. Find Center of Star Graph

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
        
        int find(){
            int ans = -1;
            for(int i=0;i<V;i++){
                if(l[i].size()==V-1){
                    ans = i;
                    break;
                }
            }
            return ans;
        }
    };
    int findCenter(vector<vector<int>>& edges) {
        int size = 0;
        for(int i=0;i<edges.size();i++){
            size = max(size,edges[i][0]);
            size = max(size,edges[i][1]);
        }
        
        Graph g(size);
        for(int i=0;i<edges.size();i++){
            g.addEdge(edges[i][0]-1,edges[i][1]-1);
        }
        
        return g.find()+1;
    }
};