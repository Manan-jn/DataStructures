//98. Validate Binary Search Tree
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
    void addPreorder(TreeNode*root,vector<int>&preorder){
        if(root==NULL){
            return;
        }
        addPreorder(root->left,preorder);
        preorder.push_back(root->val);
        addPreorder(root->right,preorder);
    }
    bool isValidBST(TreeNode* root) {
        vector<int>preorder;
        addPreorder(root,preorder);
        bool check= true;
        if(preorder.size()>1){
            for(int i=0;i<preorder.size()-1;i++){
                if(preorder[i]>=preorder[i+1]){
                    check = false;
                    break;
                }

            }
        }
        if(check){
            return true;
        }
        return false;
    }
};