//1358. Number of Substrings Containing All Three Characters
// Leetcode Medium Sliding Window

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int i=0;
        int j=0;
        int count=0;
        map<char,int>mp;
        while(j<n){
            mp[s[j]]++;
            if(mp.size()==3){
                while(mp.size()==3){
                    mp[s[i]]--;
                    if(mp[s[i]]==0){
                        mp.erase(s[i]);
                    }
                    count+= (n-j);
                    i++;
                }
            }
            j++;
        }
        return count;
    }
};