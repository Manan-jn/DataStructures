//64. Minimum Path Sum
//Leetcode Medium DP

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        vector<int>temp = grid[0];
        int col = temp.size();

        vector<vector<int>>dp(row,vector<int>(col,0));
    
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                //base case
                if(i==0 && j==0){
                    dp[i][j]= grid[i][j];
                }
                else if(i==0){
                    dp[i][j]= dp[i][j-1]+grid[i][j];
                }
                else if(j==0){
                    dp[i][j]= dp[i-1][j]+ grid[i][j];
                }
                else{
                    dp[i][j]= min(dp[i-1][j],dp[i][j-1])+ grid[i][j];
                }
            }
        }

        return dp[row-1][col-1];
    }
};