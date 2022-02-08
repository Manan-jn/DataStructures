//978. Longest Turbulent Subarray
//Leetcode Medium Sliding Window

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int i=0;
        int j=1;
        if(n==1){
            return 1;
        }
        vector<int>check;
        int ans =0;
        while(j<n){
            if(arr[j]>arr[j-1]){
                if(check.size()>0 && check.back()!=1 || check.size()==0){
                    check.push_back(1);
                }
                else{
                    check.clear();
                    check.push_back(1);
                }
            }
            else if(arr[j]<arr[j-1]){
                if(check.size()>0 && check.back()!=-1 || check.size()==0){
                    check.push_back(-1);
                } 
                else{
                    check.clear();
                    check.push_back(-1);
                }
            }
            else if(arr[j]==arr[j-1]){
                check.clear();
            }
            j++;
            int size = check.size();
            ans = max(ans,size+1);
        }
        return ans;
    }
};