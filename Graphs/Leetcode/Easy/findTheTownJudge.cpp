//Easy
//997. Find the Town Judge

class Solution {
public:
    class Graph{
        public:
        int V;
        list<int>*l;
        
        Graph(int v){
            this->V = v;
            l= new list<int>[V];
        }
        
        void addEdge(int x,int y){
            l[x].push_back(y);
        }
        int find(){
            int ans = -1;
            int*indegree = new int[V];
            for(int i=0;i<V;i++){
                indegree[i]=0;
            }
            
            for(int i=1;i<V;i++){
                for(auto n:l[i]){
                    indegree[n]++;
                }
            }
            
            for(int i=1;i<V;i++){
                if(l[i].size()==0 && indegree[i]==V-2){
                    ans = i;
                    break;
                }
            }
            return ans;
        }  
        
    };
    int findJudge(int n, vector<vector<int>>& trust) {
        Graph g(n+1);
        
        for(int i=0;i<trust.size();i++){
            g.addEdge(trust[i][0],trust[i][1]);
        }
        return g.find();
    }
};