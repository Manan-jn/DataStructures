//121. Best Time to Buy and Sell Stock
//Leetcode Easy DP

class Solution {
public:
    int maxProfit(vector<int>& prices) {
     int n = prices.size();
        int minP = INT_MAX;
        int maxProfit=0;
        for(int i=0;i<n;i++){
            if(prices[i]<minP){
                minP = prices[i];
            }
            else{
                maxProfit = max(prices[i]-minP,maxProfit);
            }
        }
        return maxProfit;
    }
};