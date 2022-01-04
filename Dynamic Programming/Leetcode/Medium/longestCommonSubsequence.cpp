//1143. Longest Common  Subsequence
//Leetcode Medium DP

class Solution {
public:    
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        for(int i=1;i<n1+1;i++){
            for(int j=1;j<n2+1;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]= 1+ dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n1][n2];
    }
};