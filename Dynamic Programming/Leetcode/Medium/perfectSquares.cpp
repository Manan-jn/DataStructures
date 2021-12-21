//279. Perfect Squares
//Leetcode Medium DP

class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+1,0);
        dp[0]=0;
        dp[1]=1;
        int count =1;
        for(int i=2;i<=n;i++){
            int count =1;
            int countMin =INT_MAX;
            while(count*count<=i){
                int temp = dp[i-count*count];
                countMin = min(countMin,temp);
                count++;
            }
            dp[i]= countMin +1;
        }
        return dp[n];
    }
};