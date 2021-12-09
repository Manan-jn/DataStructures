//111. Minimum Depth of Binary Tree
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
    int minD=INT_MAX;
    void check(TreeNode*root,vector<int>&res){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            res.push_back(root->val);
            int s = res.size();
            minD = min(minD,s);
            res.pop_back();
        }
        res.push_back(root->val);
        check(root->left,res);
        check(root->right,res);
        res.pop_back();
    }
    int minDepth(TreeNode* root) {
       vector<int>res;
        if(root!=NULL){
            check(root,res);
            return minD;
        }
        return 0;
    }
};