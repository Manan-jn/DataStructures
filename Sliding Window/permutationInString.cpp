//567. Permutation in String
//Leetcode Medium Sliding Window

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        map<char,int>mp;
        for(int i=0;i<n;i++){
            mp[s1[i]]++;
        }
        int i=0;
        int j=0;
        int flag=0;
        int count = mp.size();
        while(j<s2.length()){
            if(mp.find(s2[j])!=mp.end()){
                mp[s2[j]]--;
                if(mp[s2[j]]==0){
                  count--;
                }
            }
            if(j-i+1<n){
                j++;
            }
            else if(j-i+1==n){
                if(count==0){
                    flag=1;
                    break;
                }
                if(mp.find(s2[i])!=mp.end()){
                    if(mp[s2[i]]==0){
                        count++;
                    }
                    mp[s2[i]]++;
                }
                i++;
                j++;
            }
        }
        if(flag==1){
            return true;
        }
        return false;
    }
};