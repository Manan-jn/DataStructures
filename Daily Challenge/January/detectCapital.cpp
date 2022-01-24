//520. Detect Capital
//24th January

class Solution {
public:
    bool detectCapitalUse(string word) {
       int n = word.length();
        int count =0;
        for(int i=0;i<n;i++){
            if(int(word[i])<=90 && int(word[i])>=65){
                count++;
            }
        }
        if(count==n || (count==1 && word[0]<=90 && word[0]>=65) || count==0){
            return true;
        }
        return false;
    }
};