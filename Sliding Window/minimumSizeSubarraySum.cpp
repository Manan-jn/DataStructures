//209. Minimum Size Subarray Sum
//Leetcode Medium Sliding window

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
     int n = nums.size();
        int sum =0;
        int i=0;
        int j=0;
        int ans =INT_MAX;
        while(j<n){
            sum = sum + nums[j];
            if(sum<target){
                j++;
            }
            else if(sum>=target){
                ans = min(ans,j-i+1);
                while(sum>=target){
                    ans = min(ans,j-i+1);
                    sum = sum - nums[i];
                    i++;
                }
                j++;
            }
        }
        if(ans!=INT_MAX){
            return ans;
        }
        return 0;
        
    }
};