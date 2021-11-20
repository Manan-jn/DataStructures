//653. Two Sum IV - Input is a BST
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
class Solution {
public:
    void preorderTrav(TreeNode*root,vector<int>&preorder){
        if(root==NULL){
            return;
        }
        preorderTrav(root->left,preorder);
        preorder.push_back(root->val);
        preorderTrav(root->right,preorder);
    }
    bool findTarget(TreeNode* root, int k) {
        
        vector<int>preorder;
        preorderTrav(root,preorder);
        
        int i =0;
        int j = preorder.size()-1;
        bool res = false;
        while(i<j){
            int sum = preorder[i]+preorder[j];
            if(sum==k){
                res = true;
                break;
            }
            if(sum>k){
                j--;
            }
            if(sum<k){
                i++;
            }
        }
        if(res){
            return true;
        }
        return false;
    }
};