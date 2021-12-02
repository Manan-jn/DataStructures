//662. Maximum Width of Binary Tree
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
    int width =1;
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long int>>q;
        if(root!=NULL){
            q.push({root,0});
            q.push({NULL,0});
        }
        long long int minIdx =0;
        while(!q.empty()){
            TreeNode*f = q.front().first;
            long long int idx = q.front().second;
            if(f==NULL){
                q.pop();
                //we need to calculate the width and update
                int lastIdx = q.back().second;
                minIdx =1+lastIdx;
                //put the null
                if(!q.empty()){
                    int lastIdx = q.back().second;
                    int frontIdx = q.front().second;
                    if(q.size()!=1){
                        width = max(width,abs(lastIdx- frontIdx) +1);
                    }
                    q.push({NULL,0});
                }
            }
            else{
                q.pop();
                //we need to update its index
                idx = idx-minIdx;
                if(f->left){
                    q.push({f->left,(2*idx)+1});
                }
                if(f->right){
                    q.push({f->right,(2*idx)+2});
                }
            }  
        }
        return width;
    }
};