//746. Min Cost Climbing Stairs
//Leetcode Easy DP

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1,0);
        for(int i=0;i<n;i++){
            dp[i]=cost[i];
        }
        for(int i=2;i<=n;i++){
            dp[i]+=min(dp[i-1],dp[i-2]);
        }
        return dp[n];
    }
};