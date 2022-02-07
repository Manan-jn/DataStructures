//389. Find the Difference
//Leetcode 7th Feb

// By using Maps c++ STL
class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = s.length();
        map<char,int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        char ch;
        for(int i=0;i<t.length();i++){
            if(mp.find(t[i])!=mp.end()){
                mp[t[i]]--;
                if(mp[t[i]]==0){
                    mp.erase(t[i]);
                }
            }
            else{
                ch = t[i];
                break;
            }
        }
        return ch;
    }
};

//By using XOR NO EXTRA SPACE
class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = s.length();
        int c =0;
        for(int i=0;i<n;i++){
            c = c^ s[i];
            c = c^ t[i];
        }
        c = c^t[t.length()-1];
        return char(c);
    }
};