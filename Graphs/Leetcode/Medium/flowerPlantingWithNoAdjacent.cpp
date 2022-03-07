//1042. Flower Planting With No Adjacent
//Leetcode Medium Graphs

class Graph{
    public:
    int V;
    list<int>*l;
    
    Graph(int v){
        this->V = v;
        l = new list<int>[v];
    }
    void addEdge(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void bfs(int src,bool*visited,int*plant){
    
        queue<int>q;
        q.push(src);
        visited[src]= true;
        while(!q.empty()){
            int f = q.front();
            q.pop();
            
            if(plant[f]==0){
                plant[f]=1;
            }
            map<int,int>mp;
            mp[plant[f]]++;
            
            for(auto n: l[f]){
                if(!visited[n]){
                    visited[n]= true;
                    for(auto nbr : l[n]){
                        mp[plant[nbr]]++;
                    }
                    for(int i=1;i<=4;i++){
                        if(mp.find(i)==mp.end()){
                            plant[n]= i;
                            break;
                        }
                    }  
                    q.push(n);
                }
            }
        }
    }
};

class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        //bfs of the graph and giving values between 1 and 4 to every garden
        
        Graph g(n+1);
        
        for(int i=0;i<paths.size();i++){
            g.addEdge(paths[i][0],paths[i][1]);
        }

        bool*visited = new bool[n+1];
        int*plant = new int[n+1];
        for(int i=0;i<n+1;i++){
            visited[i]= false;
            plant[i]=0;
        }
        
        vector<int>res;
        for(int i=1;i<n+1;i++){
            if(!visited[i]){
                g.bfs(i,visited,plant);
            }
        }
        for(int i=1;i<n+1;i++){
            res.push_back(plant[i]);
        }
        return res;
    }
};