//392. Is Subsequence
//Leetcode 2nd March

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0;
        int j=0;
        
        int count =0;
        
        while(i<t.length()){
            if(j==s.length()){
                break;
            }
            if(t[i]==s[j]){
                i++;
                j++;
                count++;
            }
            else{
                i++;
            }
        }
        if(count==s.length()){
            return true;
        }
        return false;
    }
};