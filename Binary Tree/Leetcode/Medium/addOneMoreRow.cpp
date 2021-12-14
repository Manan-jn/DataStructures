//623. Add One Row to Tree
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
    void check(TreeNode*root,int val,int depth,int currLevel){
        if(root==NULL){
            return;
        }
        if(currLevel+1==depth){
            TreeNode*l = new TreeNode(val);
            TreeNode*r = new TreeNode(val);
            TreeNode*tempL = NULL;
            TreeNode*tempR = NULL;
            if(root->left!=NULL){
                tempL = root->left;
            }
            if(root->right!=NULL){
                tempR = root->right;
            }
            root->left = l;
            root->right = r;
            l->left = tempL;
            r->right = tempR;
            return;
        }
        check(root->left,val,depth,currLevel+1);
        check(root->right,val,depth,currLevel+1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        int currLevel =1;
        if(depth>1){
            check(root,val,depth,currLevel);
        }
        if(depth==1){
            TreeNode*temp = new TreeNode(val);
            TreeNode*replace = root;
            temp->left = replace;
            temp->right = NULL;
            return temp;
        }
        return root;
    }
};