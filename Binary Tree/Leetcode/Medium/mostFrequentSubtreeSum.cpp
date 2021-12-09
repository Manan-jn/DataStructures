//508. Most Frequent Subtree Sum
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
    int count(TreeNode*root,map<int,int>&m){
        if(root==NULL){
            return 0;
        }
        int lc = count(root->left,m);
        int rc = count(root->right,m);
        int sum = root->val+lc+rc;
        m[sum]++;
        return root->val+lc+rc;        
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int,int>m;
        int maxi =0;
        int ans =0;
        count(root,m);
        for(auto p:m){
            int key = p.first;
            int count = p.second;
            int temp = maxi;
            maxi = max(maxi,count);
            if(maxi>temp){
                ans = key;
            }
        }
        vector<int>res;
        for(auto p:m){
            int key = p.first;
            int count = p.second;
            if(count == maxi){
                res.push_back(key);
            }
        }
        return res; 
    }
};