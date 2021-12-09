//450. Delete Node in a BST
//Leetcode Medium BST
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }
        if(root->val == key){
            //3 cases are there
            if(root->left==NULL && root->right==NULL){
                //Leaf node case
                delete root;
                return NULL;
            }
            if(root->left!=NULL && root->right==NULL){
                //1 children left child
                TreeNode*temp = root->left;
                delete root;
                return temp;
            }
            if(root->left==NULL && root->right!=NULL){
                TreeNode*temp = root->right;
                delete root;
                return temp;
            }
            //delete the root node
            else{
                TreeNode*replace = root->right;
                while(replace->left!=NULL){
                    replace = replace->left;
                }
                root->val = replace->val;
                root->right = deleteNode(root->right,replace->val);
                return root;
            }
        }
        else if(root->val >key){
            root->left = deleteNode(root->left,key);
        }
        else{
            root->right = deleteNode(root->right,key);
        }
        return root;
    }
};