//62. Unique Paths
//Leetcode Medium DP

class Solution {
public:
    int uniquePaths(int m, int n) {
        int row = m;
        int col = n;
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<col;i++){
            dp[0][i]=1;
        }
        for(int j=0;j<row;j++){
            dp[j][0]=1;
        }
        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                dp[i][j]= dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[row-1][col-1];
    }
};