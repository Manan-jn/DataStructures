//129. Sum Root to Leaf Numbers
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
    int sum =0;
    void addNodes(TreeNode*root,vector<int>&path){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            path.push_back(root->val);
            int power=0;
            int num =0;
            //need to calculate the number and add to the sum;
            for(int i=path.size()-1;i>=0;i--){
                num+=(path[i])*pow(10,power);
                power++;
            }
            sum+=num;
            path.pop_back();
        }
        path.push_back(root->val);
        addNodes(root->left,path);
        addNodes(root->right,path);
        path.pop_back();
        return;
    }
    int sumNumbers(TreeNode* root) {
        vector<int>path;
        addNodes(root,path);
        return sum;
    }
};