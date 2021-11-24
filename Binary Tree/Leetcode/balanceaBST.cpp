//1382. Balance a Binary Search Tree
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
    void addPreorder(TreeNode*root,vector<int>&preorder){
        if(root==NULL){
            return;
        }
        addPreorder(root->left,preorder);
        preorder.push_back(root->val);
        addPreorder(root->right,preorder);
    }
    TreeNode*constructTree(vector<int>&preorder,int s,int e){
        if(s>e){
            return NULL;
        }
        int mid = (s+e)/2;
        TreeNode*new_node = new TreeNode(preorder[mid]);
        new_node->left= constructTree(preorder,s,mid-1);
        new_node->right = constructTree(preorder,mid+1,e);
        return new_node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>preorder;
        addPreorder(root,preorder);
        TreeNode*new_node = constructTree(preorder,0,preorder.size()-1);
        return new_node;
    }
};