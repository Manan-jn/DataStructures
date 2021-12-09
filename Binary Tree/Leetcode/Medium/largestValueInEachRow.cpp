//515. Find Largest Value in Each Tree Row
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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*>q;
        if(root!=NULL){
            q.push(root);
            q.push(NULL);
        }
        vector<int>res;
        vector<int>ans;
        while(!q.empty()){
            TreeNode*f = q.front();
            if(f==NULL){
                int curr =INT_MIN;
                for(int i=0;i<res.size();i++){
                    curr = max(curr,res[i]);
                }
                ans.push_back(curr);
                res.clear();
                q.pop();
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                res.push_back(f->val);
                q.pop();
                if(f->left){
                    q.push(f->left);
                }
                if(f->right){
                    q.push(f->right);
                }
            }
        }
        return ans;
    }
};