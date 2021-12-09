//331. Verify Preorder Serialization of a Binary Tree
//Leetcode Medium Binary tree
class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<int>s;
        int flag=0;
        if(preorder[0]!='#' && preorder.length()>1){
            s.push(-1);
            s.push(-1);
        }
        else if(preorder.length()==1 && preorder[0]!='#'){
            flag=1;
        }
        int count =0;
        for(int i=1;i<preorder.length();i++){
            if(preorder[i]!=','){
                if(preorder[i]!='#'){
                    if(!s.empty()){
                        s.pop();
                        s.push(-1);
                        s.push(-1);
                    }
                    else{
                        flag=1;
                    }
                }
                if(preorder[i]=='#'){
                    count++;
                    if(!s.empty()){
                        s.pop();
                    }
                    else{
                        flag=1;
                    }
                }
            }
        }
        if(preorder.length()==1 && preorder[0]=='#'){
            flag=0;
        }
         if(flag==1 || (s.size()==1 && preorder.length()==3) || count<s.size()){
                return false;
        }
        return true;
    }
};