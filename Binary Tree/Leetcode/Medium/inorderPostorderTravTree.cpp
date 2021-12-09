//106. Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode*buildTreePost(vector<int>&inorder,vector<int>&postorder,int s,int e){
        if(s>e){
            return NULL;
        }
        int curr = postorder[i];
        TreeNode*root = new TreeNode(curr);
        int idx =-1;
        for(int j=s;j<=e;j++){
            if(inorder[j]==curr){
                idx =j;
                break;
            }
        }
        i++;
        root->right = buildTreePost(inorder,postorder,idx+1,e);
        root->left = buildTreePost(inorder,postorder,s,idx-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //pick elements from the postorder traversal one by one
        //make them the root node
        //Find their index in the inorder traversal
        //call on the left as index -1
        //call on the right with index+1
        int n = inorder.size();
        int s =0;
        int e = n-1;
        reverse(postorder.begin(),postorder.end());
        TreeNode*root = buildTreePost(inorder,postorder,s,e);
        return root;
    }
};