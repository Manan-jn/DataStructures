class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int>mp;
        int n = s.length();
        
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        
        vector<int>count;
        map<char,int>myMap;
        int countt =0;
        
        for(int i=0;i<n;i++){
            mp[s[i]]--; 
            countt++;
            myMap[s[i]]++;
     
            if(mp[s[i]]==0){                
                myMap.erase(s[i]);
                mp.erase(s[i]);
            }
            if(myMap.size()==0){
                count.push_back(countt);
                countt=0;
            }
        }
        return count;
        
    }
};