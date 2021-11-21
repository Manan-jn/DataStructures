//530. Minimum Absolute Difference in BST
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
    void calculate(TreeNode*root,vector<int>&preorder){
        if(root==NULL){
            return;
        }
        calculate(root->left,preorder);
        preorder.push_back(root->val);
        calculate(root->right,preorder);
    }
    int getMinimumDifference(TreeNode* root) {
       vector<int>preorder;
        calculate(root,preorder);
        int minDiff=INT_MAX;
        for(int i=0;i<preorder.size()-1;i++){
            int first = preorder[i];
            int second = preorder[i+1];
            int diff = abs(second -first);
            minDiff = min(minDiff,diff);
        }
        return minDiff;
    }
};