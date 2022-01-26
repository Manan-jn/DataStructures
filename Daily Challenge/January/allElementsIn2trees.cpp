//1305. All Elements in Two Binary Search Trees
//26th January

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
    vector<int>list1;
    vector<int>list2;
    void tree1(TreeNode*root1){
        if(root1==NULL){
            return;
        }
        tree1(root1->left);
        list1.push_back(root1->val);
        tree1(root1->right);
    }
     void tree2(TreeNode*root2){
        if(root2==NULL){
            return;
        }
        tree2(root2->left);
        list2.push_back(root2->val);
        tree2(root2->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        tree1(root1);
        tree2(root2);
        for(int i=0;i<list2.size();i++){
            list1.push_back(list2[i]);
        }
        sort(list1.begin(),list1.end());
        return list1;
    }
};