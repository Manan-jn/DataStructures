//941. Valid Mountain Array
//25th January

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        int idx =-1;
        int prev =-1;
        if(n<=2){
            return false;
        }
        for(int i=0;i<n;i++){
            if(arr[i]>prev){
                prev = arr[i];
                idx =i;
            }
            else if(arr[i]==prev){
                return false;
            }
            else{
                break;
            }
        }
        if(idx==n-1 || idx==0){
            return false;
        }
        int i=idx+1;
        for(i;i<n;i++){
            if(arr[i]>=arr[i-1]){
                return false;
            }
        }
        return true;   
    }
};