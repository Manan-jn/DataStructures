//118. Pascal's Triangle
//Leetcode Easy DP

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>dp;
        vector<int>temp;
        if(numRows==0){
            return dp;
        }
        temp.push_back(1);
        dp.push_back(temp);
        for(int i=1;i<numRows;i++){
            vector<int>row = dp[i-1];
            vector<int>temp1;
            temp1.push_back(1);
            for(int i=0;i<row.size()-1;i++){
                temp1.push_back(row[i]+row[i+1]);
            }
            temp1.push_back(1);
            dp.push_back(temp1);
        }
        return dp;
    }
};