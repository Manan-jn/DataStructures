//105. Construct Binary Tree from Preorder and Inorder Traversal
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
    int i=0;
    TreeNode* buildTreeInorder(vector<int>&preorder,vector<int>&inorder,int s,int e){
        if(s>e){
            return NULL;
        }
        int curr = preorder[i];
        int idx=-1;
        for(int j=s;j<=e;j++){
            if(inorder[j]==curr){
                idx=j;
                break;
            }
        }
        i++;
        TreeNode*root = new TreeNode(curr);
        root->left = buildTreeInorder(preorder,inorder,s,idx-1);
        root->right = buildTreeInorder(preorder,inorder,idx+1,e);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //need to chose the first element of the preorder and make the node
        //search for the elements in the inorder array
        int s =0;
        int e = inorder.size()-1;
        TreeNode*root = buildTreeInorder(preorder,inorder,s,e);
        return root;
    }
};