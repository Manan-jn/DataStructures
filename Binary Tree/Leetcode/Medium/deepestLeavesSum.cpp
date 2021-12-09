//1302. Deepest Leaves Sum
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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*>q;
        if(root!=NULL){
            q.push(root);
            q.push(NULL);
        }
        vector<int>temp;
        int sum =0;
        while(!q.empty()){
            TreeNode*f = q.front();
            if(f==NULL){
                q.pop();
                if(!q.empty()){
                    q.push(NULL);
                }
                sum=0;
                for(int i=0;i<temp.size();i++){
                    sum +=temp[i];
                }
                temp.clear();
            }
            else{
                temp.push_back(f->val);
                q.pop();
                if(f->left){
                    q.push(f->left);
                }
                if(f->right){
                    q.push(f->right);
                }
            }
        }
        return sum;
    }
};