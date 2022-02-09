//1208. Get Equal Substrings Within Budget
//Leetcode Medium Sliding Window

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        int cost =0;
        int len = 0;
        int i=0;
        int j=0;
        while(j<n){
            if(abs(t[j]-s[j])+cost<=maxCost){
                cost += abs(t[j]-s[j]);
                len = max(len,j-i+1);
            }
            else if(abs(t[j]-s[j])+cost>maxCost){
                while(abs(t[j]-s[j])+cost>maxCost){
                    cost -= abs(t[i]-s[i]);
                    i++;
                }
                if(abs(t[j]-s[j])+cost<=maxCost){
                    cost+=abs(t[j]-s[j]);
                    len = max(len,j-i+1);
                }
            }
            j++;
        }
        return len;
    }
};