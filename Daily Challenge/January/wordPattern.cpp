//290. Word Pattern
//17th January

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char,string>mp;
        int n = pattern.length();
        int m = s.length();
        int j=0;
        int flag=0;
        int count =0;
        for(int i=0;i<m;i++){
            if(s[i]==' '){
                count++;
            }
        }
        if(count+1!=n){
            return false;
        }
        for(int i=0;i<n;i++){
            char curr = pattern[i];
            string str;
            if(s[j]=='\0'){
                break;
            }
            while(j<m && s[j] != ' '){
                str+=s[j];
                j++;
            }
            if(j!=m){
                if(s[j]==' '){
                    j++;
                }
            }
            auto itr = mp.find(curr);
            if(itr!=mp.end()){
                if(mp[curr]!=str){
                    flag=1;
                }
            }
            else if(itr==mp.end()){
                for(auto p:mp){
                    string temp = p.second;
                    if(temp==str){
                        flag=1;
                        break;
                    }
                }
                if(flag!=1){
                    mp[curr]= str;
                }
            }
        }
        if(flag==1){
            return false;
        }
        return true;
    }
};