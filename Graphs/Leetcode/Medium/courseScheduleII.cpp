//210. Course Schedule II
//Leetcode Medium Graphs

class Graph{
    public:
    int V;
    list<int>*l;
    Graph(int v){
        this->V = v;
        l = new list<int>[V];
    }
    
    bool dfsCycle(int node,bool*visit,bool*arr){
        visit[node]= true;
        arr[node]= true;

        for(auto n: l[node]){
            if(arr[n]==1){
                return true;
            }
            else if(!visit[n]){
                bool temp = dfsCycle(n,visit,arr);
                if(temp==true){
                    return true;
                }
            }
        }
        
        arr[node]=false;
        return false;
    }
    bool detectCycle(){
        bool*visit = new bool[V];
        bool*arr = new bool[V];
        for(int i=0;i<V;i++){
            visit[i]=false;
            arr[i]=false;
        }
        int flag=0;
        for(int node=0;node<V;node++){
            bool t = dfsCycle(node,visit,arr);
            if(t==true){
                flag=1;
                break;
            }
        }
        if(flag==1){
            return true;
        }
        return false;
    }
    void addEdge(int i,int j){
        l[i].push_back(j);
    }
    void dfsHelper(int node,bool*visited,list<int>&arr){
        visited[node]=true;
        
        for(auto n:l[node]){
            if(!visited[n]){
                dfsHelper(n,visited,arr);
            }
        }
        
        arr.push_front(node);
    }
    list<int> dfs(){
        bool*visited = new bool[V]{0};
        list<int>arr;
            for(int i=0;i<V;i++){
                if(!visited[i]){
                    dfsHelper(i,visited,arr);
                }
            }
        return arr;
    }
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
 
        Graph g(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            g.addEdge(prerequisites[i][1],prerequisites[i][0]);
        }
        vector<int>res;
        if(g.detectCycle()==false){
            list<int>a = g.dfs();
            for(auto it= a.begin();it!=a.end();it++){
                res.push_back(*it);
            }
        }
        return res;
    }
};