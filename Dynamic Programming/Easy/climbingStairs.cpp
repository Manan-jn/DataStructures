//70. Climbing Stairs
//Leetcode Easy DP
class Solution {
public:
    int climbStairs(int n) {
        int dp[100]={0};
        dp[0]=1;
        for(int i=1;i<=n;i++){
            dp[i]=0;
            for(int j=1;j<=2;j++){
                if(i-j>=0){
                    dp[i]+=dp[i-j];
                }
            }
        }
        return dp[n];
    }
};