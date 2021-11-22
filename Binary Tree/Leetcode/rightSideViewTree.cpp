//199. Binary Tree Right Side View
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
    void rightViewStore(TreeNode*root,int level,int &maxLevel,vector<int>&res){
        if(root==NULL){
            return;
        }
        if(maxLevel<level){
            res.push_back(root->val);
            maxLevel = level;
        }
        rightViewStore(root->right,level+1,maxLevel,res);
        rightViewStore(root->left,level+1,maxLevel,res);
    }
    vector<int> rightSideView(TreeNode* root) {
        int maxLevel =-1;
        vector<int>res;
        rightViewStore(root,0,maxLevel,res);
        return res;
    }
};