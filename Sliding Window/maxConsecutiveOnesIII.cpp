// /1004. Max Consecutive Ones III
//Leetcode Medium Sliding Window

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0;
        int j=0;
        int ans =0;
        if(n==1 && nums[0]==0){
            if(k==1){
                return 1;
            }
        }
        map<int,int>mp;
        while(j<n){
            mp[nums[j]]++;
            if(mp.size()<2){
                if(mp.find(1)!=mp.end()){
                    ans = max(ans,j-i+1);
                }
                j++;
            }
            else if(mp.size()==2 && mp[0]<=k){
                ans = max(ans,j-i+1);
                j++;
            }
            else if(mp[0]>k){
                while(mp[0]>k){
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0){
                        mp.erase(nums[i]);
                    }
                    i++;
                }
                if(mp.size()==2 && mp[0]<=k){
                    ans = max(ans,j-i+1);
                }
                j++;
            }
        }
        return ans;
    }
};