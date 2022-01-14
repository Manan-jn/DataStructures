//416. Partition Equal Subset Sum
// Leetcode Medium DP

class Solution {
public:
     bool canPartition(vector<int>& nums) {
        int dp[20001];
        memset(dp,-1,sizeof(dp));
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        return helper(nums,0,0,dp,totalSum);
    }
    bool helper(vector<int>&nums,int index,int sum, int dp[],int totalSum){
        if(dp[sum] != -1){
          return dp[sum];
        }
        if(index >= nums.size()){
            return (sum == (totalSum - sum));
         } 
       
        //dont include the element
        bool ans2 = helper(nums,index+1,sum+nums[index],dp,totalSum);
        bool ans1 = helper(nums,index+1,sum,dp,totalSum);
        dp[sum] = ans1 || ans2;
        return dp[sum];
    }
     
};