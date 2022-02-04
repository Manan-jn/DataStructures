//395. Longest Substring with At Least K Repeating Characters
//Leetcode Medium Sliding Window

class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        map<char,int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        int maxUnique = mp.size();
        int ans =INT_MIN;
        for(int unique=1;unique<=maxUnique;unique++){
             map<char,int>temp;
            int i=0;
            int j=0;    
            while(j<n){
                temp[s[j]]++;
                if(temp.size()<unique){
                    j++;
                }
                else if(temp.size()==unique){
                    int flag =0;
                    for(auto x:temp){
                        if(x.second<k){
                            flag =1;
                            break;
                        }
                    }
                    if(flag==0){
                        ans = max(ans,j-i+1);
                    }
                    j++;
                }
                else if(temp.size()>unique){
                    while(temp.size()>unique){
                        temp[s[i]]--;
                        if(temp[s[i]]==0){
                            temp.erase(s[i]);
                        }
                        i++;
                    }
                    j++;
                }
            }
        }
        if(ans != INT_MIN){
            return ans;
        }
        return 0;
    }
};