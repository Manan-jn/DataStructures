//1315. Sum of Nodes with Even-Valued Grandparent
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
    int sum=0;
    void printAtLevelK(TreeNode*root,int k){
        if(root==NULL){
            return;
        }
        if(k==0){
            sum+=root->val;
        }
        printAtLevelK(root->left,k-1);
        printAtLevelK(root->right,k-1);
    }
    void count(TreeNode*root){
        if(root==NULL){
            return;
        }
        if(root->val%2==0){
            printAtLevelK(root,2);
        }   
        count(root->left);
        count(root->right);
    }
    int sumEvenGrandparent(TreeNode* root) {
        count(root);
        return sum;
    }
};