//1038. Binary Search Tree to Greater Sum Tree
//Leetcode Medium BST
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
    int sum =0;
    void preorderTrav(TreeNode*root,vector<pair<TreeNode*,int>>&preorder){
        if(root==NULL){
            return;
        }
        preorderTrav(root->left,preorder);
        preorder.push_back(make_pair(root,root->val));
        preorderTrav(root->right,preorder);
    }
    TreeNode* bstToGst(TreeNode* root) {
        vector<pair<TreeNode*,int>>preorder;
        preorderTrav(root,preorder);
      
        for(int i=0;i<preorder.size();i++){
            sum+=preorder[i].second;
            preorder[i].second = sum;
        }
        int last = preorder[preorder.size()-1].second;
        for(int i=0;i<preorder.size();i++){
            TreeNode*curr = preorder[i].first;
            curr->val += last - preorder[i].second;
        }
        return root;
    }
};