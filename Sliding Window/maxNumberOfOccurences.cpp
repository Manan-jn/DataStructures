//1297. Maximum Number of Occurrences of a Substring
//Leetcode Medium Sliding window

class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.length();
        map<string,int>res;
        for(int i=0;i<n;i++){
            map<char,int>mp;
            string str;
            for(int j=i;j<n;j++){
                mp[s[j]]++;
                if(j-i+1 <minSize){
                   str += s[j]; 
                }
                if(mp.size()<=maxLetters && j-i+1>=minSize && j-i+1<=maxSize){
                    str+=s[j];
                    res[str]++;
                }
                else if(j-i+1>maxSize){
                    break;
                }
            }
        }
        int ans =0;
        for(auto x: res){
            ans = max(ans,x.second);
        }
        
        return ans;
    }
};