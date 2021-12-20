//45. Jump Game II
//Leetcode Medium DP

class Solution {
public:
    int check(vector<int>&nums,int n,int i,vector<int>&dp){
        if(i==n-1){
            return 0;
        }
        if(i>=n){
            return INT_MAX;
        }
        if(dp[i]!=0){
            return dp[i];
        }
        //rec case
        int jumps = nums[i];
        int ans = INT_MAX;
        for(int j=1;j<=jumps;j++){
            int temp = check(nums,n,j+i,dp);
            if(temp!=INT_MAX){
                ans = min(ans,temp+1);
            }
        }
        dp[i]= ans;
        return ans;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        vector<int>dp(n,0);
        return check(nums,n,i,dp);
    }
};