//300. Longest Increasing Subsequence
//Leetcode Medium DP

class Solution {
public:
    // Method 1 --- O(N^2)
    int checkDp1(int n,vector<int>&nums){
        //will maintain a dp array where dp[i] represents the max length of the LIS till index i
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            //need to look back for elements
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i]= max(dp[i],dp[j]+1);
                }
            }
        }
        int lis=0;
        for(int i=0;i<n;i++){
            lis = max(lis,dp[i]);
        }
        return lis;
    }

    //Method --2 O(N^2)
    int checkDp2(int n,vector<int>&num){
        //will maintain a dp array where dp[i] represents teh element at which the LIS of length i ends
        vector<int>dp(n+1,INT_MAX);
        dp[0]= INT_MIN;
        for(int i=0;i<n;i++){
            int curr = num[i];
            for(int j=0;j<n;j++){
                if(curr<dp[j+1] && curr>dp[j]){
                    dp[j+1]= curr;
                }
            }
        }
        int lis =0;
        for(int i=1;i<=n;i++){
            if(dp[i]!=INT_MAX){
                lis =i;
            }
        }
        return lis;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        return checkDp2(n,nums); 
    }
};