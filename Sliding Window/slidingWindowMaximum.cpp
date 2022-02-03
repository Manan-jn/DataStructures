//239. Sliding Window Maximum
//Leetcode Hard Sliding Window

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0;
        int j=0;
        vector<int>ans;
        list<int>maxNums;
        while(j<n){
            while(maxNums.size()>0 && maxNums.back()< nums[j]){
                maxNums.pop_back();
            }
            maxNums.push_back(nums[j]);
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                ans.push_back(maxNums.front());   
                if(nums[i]==maxNums.front()){
                    maxNums.pop_front();
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};