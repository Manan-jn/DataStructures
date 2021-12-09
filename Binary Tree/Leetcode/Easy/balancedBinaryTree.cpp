//110. Balanced Binary Tree
//Leetcode Easy Binary Tree
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
class myPair{
    public:
    int height;
    bool balance;
};
class Solution {
public:
    myPair checkBalance(TreeNode*root){
        myPair p;
        if(root==NULL){
            p.height =0;
            p.balance = true;
            return p;
        }
        myPair l = checkBalance(root->left);
        myPair r = checkBalance(root->right);
        p.height= max(l.height,r.height)+1;
        if(abs(l.height-r.height)<=1 && l.balance && r.balance){
            p.balance = true;
            return p;
        }
        p.balance = false;
        return p;
    }
    bool isBalanced(TreeNode* root) {
        myPair p = checkBalance(root);
        return p.balance;
    }
};