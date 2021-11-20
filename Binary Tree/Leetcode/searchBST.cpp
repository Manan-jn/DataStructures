//700. Search in a Binary Search Tree
//Leetcode Binary Tree Easy
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

    TreeNode* searchBST(TreeNode* root, int val) {
        
        if(root==NULL){
            return NULL;
        }
        TreeNode*l=NULL;
        TreeNode*r=NULL;
        if(root->val == val){
            return root;
        }
        if(val> root->val){
            l= searchBST(root->right,val);
        }
        else if(val <root->val){
            r = searchBST(root->left,val);
        }
        if(l){
            return l;
        }
        return r;
        
    }
};