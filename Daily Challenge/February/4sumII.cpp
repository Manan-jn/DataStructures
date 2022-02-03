//454. 4Sum II
//3rd Feb

//BRUTE FORCE APPROACH O(N^2)
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        map<int,int>mp1;
        int sum =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum = nums1[i]+nums2[j];
                mp1[sum]++;
            }
        }
        map<int,int>mp2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum = nums3[i]+nums4[j];
                mp2[sum]++;
            }
        }
        int count =0;
        for(auto x:mp1){
            int key1 = x.first;
            for(auto y: mp2){
                int key2 = y.first;
                if(key1+key2==0){
                    count+=(x.second*y.second);
                }
            }
        }
        return count;
        
    }
};