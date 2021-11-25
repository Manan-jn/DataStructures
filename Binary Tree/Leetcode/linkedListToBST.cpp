//109. Convert Sorted List to Binary Search Tree
//Leetcode Medium BST
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode*convertTree(vector<int>&listTrav,int s,int e){
       if(s>e){
           return NULL;
       }
        int mid = (s+e)/2;
        TreeNode*root = new TreeNode(listTrav[mid]);
        root->left = convertTree(listTrav,s,mid-1);
        root->right = convertTree(listTrav,mid+1,e);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>listTrav;
        while(head!=NULL){
            listTrav.push_back(head->val);
            head= head->next;
        }
        int s = 0;
        int e = listTrav.size()-1;
        TreeNode*root = convertTree(listTrav,s,e);
        return root;
    }
};