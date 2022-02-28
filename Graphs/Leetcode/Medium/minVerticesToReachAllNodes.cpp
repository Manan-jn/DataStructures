//1557. Minimum Number of Vertices to Reach All Nodes
//Leetcode Medium Graphs

class Graph{
    public:
    int V;
    list<int>*l;
    Graph(int v){
        this->V= v;
        l= new list<int>[V];
    }
    void addEdge(int i,int j){
        l[i].push_back(j);
    }
    vector<int> indegree(){
        int*indegree = new int[V]{0};
        for(int i=0;i<V;i++){
            for(auto n: l[i]){
                indegree[n]++;
            }
        }
        vector<int>res;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                res.push_back(i);
            }
        }
        return res;
    }
};
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        Graph g(n);
        for(int i=0;i<edges.size();i++){
            g.addEdge(edges[i][0],edges[i][1]);
        }
        return g.indegree();
    }
};