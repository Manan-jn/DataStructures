//1423. Maximum Points You Can Obtain from Cards
//Leetcode Medium Sliding Window

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int i=0;
        int j=0;
        int ans =0;
        int sum =0;
        int totalSum =0;
        for(int i=0;i<n;i++){
            totalSum+= cardPoints[i];
        }
        if(n==k){
            return totalSum;
        }
        while(j<n){
            sum+= cardPoints[j];
            if(j-i+1<n-k){
                j++;
            }
            else if(j-i+1==n-k){
                ans = max(ans,totalSum-sum);
                sum = sum - cardPoints[i];
                i++;
                j++;
            }
        }
        return ans;
    }
};