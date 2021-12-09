//897. Increasing Order Search Tree
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
    int i=0;
    void preCalculate(TreeNode*root,vector<int>&preOrder){
        if(root==NULL){
            return;
        }
        preCalculate(root->left,preOrder);
        preOrder.push_back(root->val);
        preCalculate(root->right,preOrder);
    }
    TreeNode*buildTree(vector<int>&preorder){
        if(i==preorder.size()){
            return NULL;
        }
        int data = preorder[i];
        i++;
        TreeNode*newroot = new TreeNode(data);
        newroot->right = buildTree(preorder);
        return newroot;
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int>preOrder;
        preCalculate(root,preOrder);
        TreeNode*newRoot = NULL;
        newRoot = buildTree(preOrder);
        return newRoot;
    }
};