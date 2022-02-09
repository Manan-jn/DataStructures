//532. K-diff Pairs in an Array
//9th Feb

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
     int n = nums.size();
        int count =0;
        map<pair<int,int>,int>mp;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                
                if(abs(nums[j]-nums[i])==k){
                    if(mp.find(make_pair(nums[i],nums[j]))==mp.end() && mp.find(make_pair(nums[j],nums[i]))==mp.end()){
                        count++;
                        mp[make_pair(nums[i],nums[j])]++;
                    }
                    
                }
            }
        }
        return count;
    }
};