//438. Find All Anagrams in a String
//2nd Feb

class Solution {
public:
    map<char,int>mp;
    vector<int> findAnagrams(string s, string p) {
        int m = s.length();
        int n = p.length();
        
        for(int i=0;i<n;i++){
            mp[p[i]]++;
        }
        string str;
        vector<int>idx;
        for(int i=0;i<n;i++){
            str += s[i];
        }
        map<char,int>temp;
        for(int i=0;i<str.length();i++){
            temp[str[i]]++;
        }
        if(std::equal(mp.begin(), mp.end(),temp.begin()) == true){
            idx.push_back(0);
        }
        for(int i=n;i<m;i++){
            temp[s[i]]++;
            str+=s[i];
            temp[str[0]]--;
            if(temp[str[0]]==0){
                temp.erase(str[0]);
            }
            str.erase(0,1); 
            if(std::equal(mp.begin(), mp.end(),temp.begin()) == true){
                idx.push_back(i-n+1);
            }
        }
        return idx;
    }
};