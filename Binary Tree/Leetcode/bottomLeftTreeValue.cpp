//513. Find Bottom Left Tree Value
//Leetcode Medium Binary Tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int temp=0;
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*>q;
        if(root!=NULL){
            q.push(root);
            temp= root->val;
            q.push(NULL);
        }
        while(!q.empty()){
            TreeNode*f = q.front();
            if(f==NULL){
                q.pop();
                if(!q.empty()){
                    TreeNode*ans = q.front();
                    temp = ans->val;
                    q.push(NULL);
                }
            }
            else{
                q.pop();
                if(f->left){
                    q.push(f->left);
                }
                if(f->right){
                    q.push(f->right);
                }
            }
        }
        return temp;
    }
};