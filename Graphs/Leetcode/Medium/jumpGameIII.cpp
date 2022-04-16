//1306. Jump Game III
//Leetcode Medium Graphs

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        
        queue<int>q;
        q.push(start);
        int flag =0;
        int*vis = new int[n]{0};
        vis[start]=1;
        
        while(!q.empty()){
            int f = q.front();
            int val = arr[f];
            if(val==0){
                flag =1;
                break;
            }
            q.pop();
            if(f+val<=n-1 && vis[f+val]==0){
                vis[f+val]=1;
                q.push(f+val);
            }
            if(f-val>=0 && vis[f-val]==0){
                vis[f-val]=1;
                q.push(f-val);
            }
        }
        if(flag==1){
            return true;
        }
        return false;
    }
};