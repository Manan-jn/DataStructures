//1672. Richest Customer Wealth
//31st January

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int row = accounts.size();
        int col = accounts[0].size();
        int maxW=INT_MIN;
        for(int i=0;i<row;i++){
            int temp = 0;
            for(int j=0;j<col;j++){
                temp+=accounts[i][j];
            }
            maxW = max(maxW,temp);
        }
        return maxW;
    }
};