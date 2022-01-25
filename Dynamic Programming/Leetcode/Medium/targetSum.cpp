///494. Target Sum
//Leetcode Medium DP

class Solution {
public:
    int countSubsets(vector<int>&nums,int sum,int n){
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(i==0){
                    dp[i][j]=0;
                }
                if(j==0){
                    dp[i][j]=1;
                }
                else if (i>=1 && (nums[i-1] > j || nums[i-1] == 0)){
                    dp[i][j] = dp[i-1][j];
                }
                else if(i>=1) {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j - nums[i-1]];
                }
            }
        }
        return dp[n][sum];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==1){
            if(nums[0]==target){
                return 1;
            }
            if(nums[0]==(-1)*(target)){
                return 1;
            }
            else{
                return 0;
            }
        }
        int sum = 0;
        int zeroes=0;
        for(int i=0;i<n;i++){
            sum +=nums[i];
            if(nums[i]==0){
                zeroes++;
            }
        }
        int targetSum = (target+sum)/2;
        if((target+sum)%2!=0 || target>sum){
            return 0;
        }
       return countSubsets(nums,targetSum,n)*pow(2,zeroes);
        
    }
};