//101. Symmetric Tree
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
    bool check(TreeNode*leftNode,TreeNode*rightNode){
        if(rightNode==NULL && leftNode==NULL){
            return true;
        }
        if(rightNode==NULL || leftNode==NULL){
            return false;
        }
        if(leftNode->val!=rightNode->val){
            return false;
        }
        bool rSub= check(leftNode->left,rightNode->right);
        bool lSub= check(leftNode->right,rightNode->left);
        if(rSub==false || lSub==false){
            return false;
        }
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        TreeNode*leftNode = NULL;
        TreeNode*rightNode = NULL;
        if(root->left!=NULL){
            leftNode = root->left;
        }
        if(root->right!=NULL){
            rightNode = root->right;
        }
        bool res = check(leftNode,rightNode);
        return res;
    }
};