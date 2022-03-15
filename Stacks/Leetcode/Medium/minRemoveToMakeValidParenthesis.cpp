//1249. Minimum Remove to Make Valid Parentheses
//Leetcode Medium Stacks

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>myStack;
        
        int n = s.length();
        int i=0;
        for(i;i<n;i++){
            if(s[i]=='('){
                myStack.push(i);
            }
            else if(s[i]==')'){
                if(!myStack.empty()){
                    myStack.pop();
                }
                else{
                    s.erase(i,1);
                    i--;
                }
            }
        }
        
        while(!myStack.empty()){
            int f = myStack.top();
            s.erase(f,1);
            myStack.pop();
        }
        return s;
    }
};