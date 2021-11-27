//1161. Maximum Level Sum of a Binary Tree
//Leetcode Medium Binary tree
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
    int currLevel =0;
    int maxSum =INT_MIN;
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        if(root!=NULL){
            q.push(root);
            q.push(NULL);
        }
        vector<int>res;
        int level =0;
        while(!q.empty()){
            TreeNode*f = q.front();
            if(f==NULL){
                q.pop();
                level++;
                int sum =0;
                for(int i=0;i<res.size();i++){
                    sum+=res[i];
                }
                res.clear();
                int temp = maxSum;
                maxSum = max(sum,maxSum);
                if(maxSum>temp){
                    currLevel = level;
                }
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                q.pop();
                res.push_back(f->val);
                if(f->left){
                    q.push(f->left);
                }
                if(f->right){
                    q.push(f->right);
                }
            }
        }
        return currLevel;
    }
};