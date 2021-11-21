//671. Second Minimum Node In a Binary Tree
//Leetcode binary Tree easy
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
    void preorderTrav(TreeNode*root,set<int>&res){
        if(root==NULL){
            return;
        }
        preorderTrav(root->left,res);
        res.insert(root->val);
        preorderTrav(root->right,res);
    }
    int findSecondMinimumValue(TreeNode* root) {
            set<int>res;
        preorderTrav(root,res);
        int count =0;
        int value=-1;
        for(auto it= res.begin();it!=res.end();it++){
            count++;
            if(count==2){
                value = *it;
                break;
            }
        }
        return value;
    }
};