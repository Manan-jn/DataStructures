//1008. Construct Binary Search Tree from Preorder Traversal
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
    TreeNode*build(vector<int>&preorder,int s,int e){
        if(s>e){
            return NULL;
        }
        int curr = preorder[s];
        int idx=-1;
        for(int j=s;j<=e;j++){
            if(preorder[j]>curr){
                idx=j;
                break;
            }
        }
        TreeNode*root = new TreeNode(curr);
        if(idx==-1){
            idx=e+1;
        }
        root->left= build(preorder,s+1,idx-1);
        if(idx!=-1){
            root->right = build(preorder,idx,e);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int s =0;
        int e = preorder.size()-1;
        TreeNode*root = build(preorder,s,e);
        return root;
    }
};