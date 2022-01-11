//152. Maximum Product Subarray
//Leetcode Medium DP

class Solution {
public:

    //Brute force Approach TLE Time: O(N^2) Space: O(1)
    int maxProductBrute(vector<int>&nums){
        int n = nums.size();
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            int count= INT_MIN;
            for(int j=i;j<n;j++){
                int prod = 1;
                for(int temp = i;temp<=j;temp++){
                    prod = prod * nums[temp];
                }
                count= max(count,prod);
            }
            ans = max(ans,count);
        }
        return ans;
    }

    /* Intuition :
        The array contains both +ve and -ve integers so we need to keep record of the
        max product which have been found and the min product possible 
        and if we get the number as negative then we can reverse the min and max product 
        pointers
    */
    //Optimised Solution Time : O(N) Space: O(1)
    int maxProduct(vector<int>& nums) {
       int maxTill = nums[0];
        int minTill = nums[0];
        int ans = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0){
                swap(maxTill,minTill);
            }
            maxTill = max(nums[i],maxTill*nums[i]);
            minTill = min(nums[i],minTill*nums[i]);
            ans = max(ans,maxTill);
        }
        return ans;
    }
};