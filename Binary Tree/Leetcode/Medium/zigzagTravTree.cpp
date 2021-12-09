//103. Binary Tree Zigzag Level Order Traversal
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
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL){
            return ans;
        }
     queue<TreeNode*>q;
            q.push(root);
            q.push(NULL);
        vector<int>res;
        int count =0;
        while(!q.empty()){
            TreeNode*f = q.front();
            if(f==NULL){
                q.pop();
                count++;
                if(count%2==0){
                    reverse(res.begin(),res.end());
                    ans.push_back(res);
                }
                else if(count%2!=0){
                    ans.push_back(res);
                }
                res.clear();
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