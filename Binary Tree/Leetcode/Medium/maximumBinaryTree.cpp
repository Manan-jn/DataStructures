//654. Maximum Binary Tree
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
    TreeNode* check(vector<int>&nums,int s,int e){
        if(s>e){
            return NULL;
        }
        if(s==e){
            TreeNode*temp = new TreeNode(nums[s]);
            return temp;
        }
        int maxi=0;
        int idx =-1;
        for(int i=s;i<=e;i++){
            int temp = maxi;
            maxi = max(maxi,nums[i]);
            if(temp!=maxi){
                idx = i;
            }
        }
        TreeNode*root= new TreeNode(maxi);
        root->left = check(nums,s,idx-1);
        root->right = check(nums,idx+1,e);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        //1) Need to find the max element
        //2) The index will be i
        //3) Call on the left
        //4) Call on the right
        int s =0;
        int e = nums.size()-1;
        TreeNode*root = check(nums,s,e);
        return root;
    }
};