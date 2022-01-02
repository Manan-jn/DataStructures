//322. Coin Change
//Leetcode Medium DP

class Solution {
public:
    long long int makeChange(int amount,vector<int>&coins,vector<int>&dp,int t){
        if(amount == 0){
            return 0;
        } 
        if(dp[amount]!=0){
            return dp[amount];
        }
        long long int ans = INT_MAX;
        for(int i=0;i<t;i++){
            if(amount - coins[i]>=0){
                ans = min(ans,makeChange(amount-coins[i],coins,dp,t)+1);
            }
        }
        dp[amount] = ans;
        return ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        int t = coins.size();
        vector<int>dp(amount+1,0);
        if(makeChange(amount,coins,dp,t)!=INT_MAX){
            return makeChange(amount,coins,dp,t);
        }
        return -1;
    }
};