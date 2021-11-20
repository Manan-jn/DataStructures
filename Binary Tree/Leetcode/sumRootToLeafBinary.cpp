//1022. Sum of Root To Leaf Binary Numbers
//Leetcode Binary Tree Easy
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
    long long int sum = 0;
    int convertBinary(TreeNode*root, vector<int>&path){
        if(root==NULL){
            return sum;
        }
        if(root->left==NULL && root->right==NULL){
            path.push_back(root->val);
            long long int j=0;
            long long int dec=0;
            long long int rem =0;
            for(int i= path.size()-1;i>=0;i--){
                rem = path[i];
                dec += rem * pow(2, j);
                ++j;
            }
            sum+=dec;
            path.pop_back();
            return sum;
        }
        path.push_back(root->val);
        convertBinary(root->left,path);
        convertBinary(root->right,path);
        path.pop_back();
        return sum;
    }
    int sumRootToLeaf(TreeNode* root) {
    vector<int>path;
    long long int s = convertBinary(root,path);
    return s;
    }
};