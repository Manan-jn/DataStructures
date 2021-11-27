//1339. Maximum Product of Splitted Binary Tree
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
    long long int maxi=0;
    long long int totalSum=0;
    long long int sum(TreeNode*root){
        if(root==NULL){
            return 0;
        }
        return root->val+sum(root->left)+sum(root->right);
    }
    long long int check(TreeNode*root){
        if(root==NULL){
            return 0;
        }
        long long int l = check(root->left);
        long long int r = check(root->right);
        long long int up = totalSum - (l+r+root->val);
        long long int op1 = (root->val+r+up)*l;
        long long int op2 = (root->val+l+up)*r;
        long long int op3 = (root->val+l+r)*up;
        maxi = max(maxi,max(op1,max(op2,op3)));
        return root->val+l+r;
    }
    int maxProduct(TreeNode* root) {
        totalSum = sum(root);
        check(root);
        return maxi%1000000007;

    }
};