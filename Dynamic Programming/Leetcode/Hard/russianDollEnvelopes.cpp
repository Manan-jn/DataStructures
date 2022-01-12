//354. Russian Doll Envelopes
// Leetcode Hard DP

//Time: O(N^2) Complexity Brute DP Solution
class Solution {
public:
    static bool compareE(vector<int>a,vector<int>b){
        return b[1]>a[1];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),compareE);
        int n = envelopes.size();
      //need to check if we can place the env previous the current inside it
        vector<int>dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};