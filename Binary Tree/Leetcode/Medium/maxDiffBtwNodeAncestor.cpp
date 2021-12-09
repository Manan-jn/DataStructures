//1026. Maximum Difference Between Node and Ancestor
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
    int maxValue =0;
    void check(TreeNode*root,vector<int>&res){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            //reached the leaf node
            res.push_back(root->val);
            //check the vector found so far
            for(int i=0;i<res.size();i++){
                int curr = res[i];
                for(int j=i+1;j<res.size();j++){
                    int diff = abs(res[j]-curr);
                    maxValue = max(maxValue,diff);
                }
            }
            res.pop_back();
        }
        res.push_back(root->val);
        check(root->left,res);
        check(root->right,res);
        res.pop_back();
    }
    int maxAncestorDiff(TreeNode* root) {
        vector<int>res;
        check(root,res);
        return maxValue;
    }
};