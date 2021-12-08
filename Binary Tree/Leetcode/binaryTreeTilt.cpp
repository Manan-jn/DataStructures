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
    int tilt=0;
    int helper(TreeNode*root){
              if(root==NULL){
               return 0;
           } 
        if(root->left==NULL && root->right==NULL){
            int temp = root->val;
            root->val = 0;
            return temp;
        }
        int l = helper(root->left);
        int r = helper(root->right);
        int temp = root->val;
        root->val = abs(l-r);
        tilt+=root->val;
        return l+r+temp;
    }
    int findTilt(TreeNode* root) {
     helper(root);
        return tilt;
    }
};