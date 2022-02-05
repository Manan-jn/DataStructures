//424. Longest Repeating Character Replacement
//Leetcode Medium Sliding Window

class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans =0;
        int n = s.length();
        vector<int>count(26,0);
        int i=0;
        int j=0;
        while(j<n){
            count[s[j]-'A']++;
            int maxCount = *max_element(count.begin(),count.end());
            int size = j-i+1;
            if(size-maxCount<k){
                ans = max(ans,size);
                j++;
            }
            else if(size-maxCount == k){
                ans = max(ans,maxCount+k);
                j++;
            }
            else if(size-maxCount>k){
                while(size-maxCount>k && i<n){
                    count[s[i]-'A']--;
                    size--;
                    maxCount = *max_element(count.begin(),count.end());
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};