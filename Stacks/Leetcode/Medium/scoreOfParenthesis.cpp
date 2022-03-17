//856. Score of Parentheses
//Leetcode Medium Stacks

class Solution {
public:    
    int scoreOfParentheses(string s) {
        int n = s.length();
        
        stack<pair<char,int>>myStack;
        vector<int>v(n,-1);
        
        int i=0;
        
        while(i<n){
            
            if(s[i]=='('){
                myStack.push({s[i],i});
                i++;
            }
            
            else if(s[i]==')'){
                //pop the last char and replace the value with 1
                
                
                int sum =0;
                int l = myStack.top().second;
                int h = i;
                
                while(h>l){
                    int t = v[h];
                    if(t!=-1){
                        sum += t;
                        v[h]=-1;
                    }
                    h--;
                }
                myStack.pop();
                if(sum>0){
                    sum = 2*sum;
                    v[i]= sum;
                }
                else{
                    v[i]=1;
                }
                i++;
                //while loop till we get the char ( will pop the characters
                //if we get the chars as numbers then add them
                //when we will reach to ( will multiply by 2 the sum that we got and add to the answer
            } 
            
        }
        int ans =0;
        for(int i=0;i<n;i++){
            if(v[i]!=-1){
                ans +=v[i];
            }
        }
        return ans;
    }
};