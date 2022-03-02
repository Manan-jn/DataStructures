//1376. Time Needed to Inform All Employees
//Leetcode Medium Graphs

class Graph{
    public:
    int V;
    list<int>*l;
    
    Graph(int v){
        this->V =v;
        l = new list<int>[V];
    }
    void addEdge(int i,int j){
        l[i].push_back(j);
        l[j].push_back(i);
    }
    int bfs(int headID,vector<int>&informTime){
        queue<int>q;
        bool*visited = new bool[V]{0};
        int*time = new int[V];
        
        for(int i=0;i<V;i++){
            time[i]=0;
        }
        
        q.push(headID);
        visited[headID]=true;
        
        while(!q.empty()){
            int f = q.front();
            q.pop();
            
            for(auto n: l[f]){
                if(!visited[n]){
                    visited[n]=true;
                    q.push(n);
                    time[n]+= time[f] + informTime[f];
                }
            }
        }
        int ans=0;
        for(int i=0;i<V;i++){
            ans = max(ans,time[i]);
        }
        return ans;
    }
};

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        Graph g(n);
        for(int i=0;i<manager.size();i++){
            if(manager[i]!=-1){
                g.addEdge(manager[i],i);
            }
        }
        return g.bfs(headID,informTime);
    }
};