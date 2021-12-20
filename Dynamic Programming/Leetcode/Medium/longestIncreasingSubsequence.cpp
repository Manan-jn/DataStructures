//300. Longest Increasing Subsequence
//Leetcode Medium DP
class Solution {
public:
    void check(vector<int>&nums,int n,vector<int>&dp,int i){
        if(i==n){
            return;
        }
        int maxCount =0;
        for(int j=i-1;j>=0;j--){
            if(nums[i]>nums[j]){
                maxCount  = max(maxCount,dp[j]);
            }
        }
        dp[i]= 1+maxCount;
        check(nums,n,dp,i+1);
        return;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,0);
        dp[0]=1;
        int i=1;
        check(nums,n,dp,i);
        int ans =0;
        for(int i=0;i<n;i++){
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};