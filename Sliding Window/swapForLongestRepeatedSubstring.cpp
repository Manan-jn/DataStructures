//1156. Swap For Longest Repeated Character Substring
//Leetcode Medium Sliding Window

class Solution {
public:
    int maxRepOpt1(string text) {
        int n = text.length();
        map<char,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[text[i]].push_back(i);
        }
        int ans =0;
        for(auto x:mp){
            char ch = x.first;
            vector<int>indexes = x.second;
            int cur =1;
            int pre =0;
            int count =0;
            for(int i=1;i<indexes.size();i++){
                if(indexes[i]== indexes[i-1]+1){
                    cur++;
                }
                else if(indexes[i] == indexes[i-1]+2){
                    pre = cur;
                    cur = 1;
                }
                else{
                    pre =0;
                    cur =1;
                }
               count = max(count,pre+cur); 
            }
            if(count<indexes.size()){
                ans = max(ans,count+1);
            }
            else{
                ans = max(ans,count);
            }
        }
        return ans;
    }
};