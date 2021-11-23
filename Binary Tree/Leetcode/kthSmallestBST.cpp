//230. Kth Smallest Element in a BST
//Leetcode Medium Binary Tree (BST)
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
    void addPreorder(TreeNode*root,vector<int>&preorder){
        if(root==NULL){
            return;
        }
        addPreorder(root->left,preorder);
        preorder.push_back(root->val);
        addPreorder(root->right,preorder);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>preorder;
        addPreorder(root,preorder);
        int res =-1;
        for(int i=0;i<k;i++){
            if(i==k-1){
                res= preorder[i];
            }
        }
        return res;
    }
};