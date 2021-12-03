//222. Count Complete Tree Nodes
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
    int countNodes(TreeNode* root) {
       if(root==NULL){
           return 0;
       } 
        //need to calculate the height of the left subtree and right subtree
        int lh = findHeightLeft(root);
        int rh = findHeightRight(root);
        if(lh==rh){
            int count = (1<<lh)-1;
            return count;
        }
        return 1 + countNodes(root->left)+ countNodes(root->right);
    }
    int findHeightLeft(TreeNode*root){
        //need to find the left height
        int ht =0;
        TreeNode*temp = root;
        while(temp){
            ht++;
            temp= temp->left;
        }
        return ht;
    }
    int findHeightRight(TreeNode*root){
        //Need to find the right height
        int ht =0;
        TreeNode*temp = root;
        while(temp){
            ht++;
            temp = temp->right;
        }
        return ht;
    }
};