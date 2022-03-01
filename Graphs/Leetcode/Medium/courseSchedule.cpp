//207. Course Schedule
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
    
    bool dfsHelper(int node,bool*visited,bool*arr){
        visited[node]= true;
        arr[node]= true;
        
        for(auto n: l[node]){

            if(!visited[n]){
                bool t = dfsHelper(n,visited,arr);
                if(t==true){
                    return true;
                }
            }
            else if(arr[n]== true){
                return true;
            }
        }
        arr[node]= false;
        return false;
    }
    
    bool dfs(){
        bool*visited= new bool[V]{0};
        bool*arr = new bool[V]{0};
        
        bool t= false;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                t = dfsHelper(i,visited,arr);
                if(t==true){
                    break;
                }
            }
        }
        if(t==false){
            return true;
        }
        return false;
    }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
          //check for DAG
        if(prerequisites.size()==0){
            return true;
        }
        Graph g(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            g.addEdge(prerequisites[i][1],prerequisites[i][0]);
        }
        return g.dfs();
    }
};