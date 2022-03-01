//338. Counting Bits
//Leetcode 1st March

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>res;
        
        for(int i=0;i<=n;i++){
            int curr = i;
            int ans =0;
            while(curr>0){
                if((curr&1)==1){
                    ans++;
                }
                curr = curr>>1;
            }
            res.push_back(ans);
        }
        return res;
    }
};