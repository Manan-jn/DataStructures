//990. Satisfiability of Equality Equations
//Leetcode Medium Graphs

class Solution {
public:
    
    int findSet(int i,int*parent){
        if(parent[i]==-1){
            return i;
        }
        return findSet(parent[i],parent);
    }
    
    void unionSet(int i,int j,int*parent){
        int s1 = findSet(i,parent);
        int s2 = findSet(j,parent);
        if(s1!=s2){
            parent[s2]=s1;
        }
    }
    
    bool equationsPossible(vector<string>& equations) {
        
        int*parent = new int[27];
        for(int i=0;i<27;i++){
            parent[i]=-1;
        }
        int flag =0;
        
        for(int i=0;i<equations.size();i++){
            string s = equations[i];
            int char1 = s[0]-'a';
            int char2 = s[3]-'a';
            string sign;
            sign+=s[1];
            sign+=s[2];
            
            int s1 = findSet(char1,parent);
            int s2 = findSet(char2,parent);
            
            if(sign=="=="){
                unionSet(char1,char2,parent);
            }
        }
        
        for(int i=0;i<equations.size();i++){
            string s = equations[i];
            int char1 = s[0]-'a';
            int char2 = s[3]-'a';
            string sign;
            sign+=s[1];
            sign+=s[2]; 
            
            if(sign=="!="){
                  int s1 = findSet(char1,parent);
                    int s2 = findSet(char2,parent);
                if(s1==s2){
                    flag=1;
                    break;
                }
            }
        }
        if(flag==1){
            return false;
        }
        return true;
    }
};