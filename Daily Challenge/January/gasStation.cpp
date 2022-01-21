//134. Gas Station
//21st January

class Solution {
public:
    bool check(vector<int>&gas,vector<int>&cost,int idx,int n){
        int sgas = gas[idx];
        if(sgas<=0){
            return false;
        }
        int scost = 0;
        int flag=0;
        for(int i=1;i<=n;i++){
            if(idx+i<=n-1){
                if(sgas-cost[i+idx-1]<0){
                    flag=1;
                    break;
                }
                sgas = sgas - cost[i+idx-1] + gas[i+idx];
            }
            else if(i+idx>n-1){
                int temp = (i+idx)%(n);
                if(temp==0){
                    if(sgas-cost[n-1]<0){
                        flag=1;
                        break;
                    }
                    sgas = sgas - cost[n-1] + gas[temp];
                }
                else{
                    if(sgas-cost[temp-1]<0){
                        flag=1;
                        break;
                    }
                    sgas = sgas - cost[temp-1] + gas[temp];
                }
            }
        }
        if(flag==1){
            return false;
        }
        return true;
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = cost.size();
        int sgas = 0;
        int scost = 0;
        int idx = -1;
        int flag = 0;
        for(int i=0;i<n;i++){
            idx =i;
            if(check(gas,cost,idx,n)==true){
                flag=1;
                break;
            }       
        }
        if(flag == 1){
            return idx;
        }
        return -1;
    }
};