//1695. Maximum Erasure Value
//Leetcode Medium Sliding Window

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        int j=0;
        map<int,int>mp;
        int sum =0;
        int ans =0;
        while(j<n){
            mp[nums[j]]++;
            sum+=nums[j];
            if(mp.size()<j-i+1){
                while(mp.size()<j-i+1){
                    mp[nums[i]]--;
                    sum-=nums[i];
                    if(mp[nums[i]]==0){
                        mp.erase(nums[i]);
                    }
                    i++;
                }
                j++;
            }
            else if(mp.size()==j-i+1){
                ans = max(ans,sum);
                j++;
            }
        }
        return ans;
    }
};