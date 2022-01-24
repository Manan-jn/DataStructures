//2149. Rearrange Array Elements by Sign
//Leetcode Medium

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>neg;
        vector<int>pos;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                neg.push_back(nums[i]);
            }
            if(nums[i]>0){
                pos.push_back(nums[i]);
            }
        }
        vector<int>res;
        res.push_back(pos[0]);
        int i=1;
        int j=0;
        while(j<neg.size() && i<pos.size()){
            res.push_back(neg[j]);
            j++;
            res.push_back(pos[i]);
            i++;
        }
        while(j<neg.size()){
            res.push_back(neg[j]);
            j++;
        }
        while(i<pos.size()){
            res.push_back(pos[i]);
            i++;
        }
        return res;
    }
};