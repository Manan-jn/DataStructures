//1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree
//Leetcode Medium Binary Tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode*search(TreeNode*original,TreeNode*cloned,int key){
        if(original==NULL || cloned==NULL){
            return NULL;
        }
        if(original->val == key && cloned->val ==key){
            return cloned;
        }
        TreeNode*left = search(original->left,cloned->left,key);
        TreeNode*right = search(original->right,cloned->right,key);
        if(left!=NULL && right==NULL){
            return left;
        }
        return right;
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target)  {
        int key = target->val;
        TreeNode*found = search(original,cloned,key);
        return found;
    }
};