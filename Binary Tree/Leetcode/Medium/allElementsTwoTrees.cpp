//1305. All Elements in Two Binary Search Trees
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
    void traverse(TreeNode*root,vector<int>&inorder1){
        if(root==NULL){
            return;
        }
        traverse(root->left,inorder1);
        inorder1.push_back(root->val);
        traverse(root->right,inorder1);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>inorder1;
        vector<int>inorder2;
        if(root1!=NULL){
        traverse(root1,inorder1);
        }
        if(root2!=NULL){
        traverse(root2,inorder2);
        }
        vector<int>res;
        for(int i=0;i<inorder1.size();i++){
            res.push_back(inorder1[i]);
        }
        for(int i=0;i<inorder2.size();i++){
            res.push_back(inorder2[i]);
        }
        sort(res.begin(),res.end());
        return res;
    }
};