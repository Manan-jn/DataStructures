//114. Flatten Binary Tree to Linked List
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
 //Time -- O(N)
 //Space -- O(N)
class Solution {
public:
    void flatten(TreeNode* root) {
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            TreeNode*curr = st.top();
            st.pop();
            if(curr!=NULL){
                if(curr->right!=NULL){
                    st.push(curr->right);
                }
                if(curr->left!=NULL){
                    st.push(curr->left);
                }
                if(!st.empty()){
                    curr->right = st.top();
                }
                curr->left=NULL;
            }
        }
        return;
    }
};

//Time -- O(N)
//Space -- O(1)
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode*curr = root;
        while(curr!=NULL){
            if(curr->left!=NULL){
                TreeNode*prev = curr->left;
                while(prev->right){
                    prev= prev->right;
                }
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left=NULL;
            }
            curr= curr->right;
        }
        return;
    }
};