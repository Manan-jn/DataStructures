//257. Binary Tree Paths
//Leetcode Binary Tree Easy
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
    void check(TreeNode*root,vector<int>&path,vector<string>&paths){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            string temp="";
            path.push_back(root->val);
            for(int i=0;i<path.size();i++){
                if(i!=path.size()-1){
                    int value = path[i];
                    string str = to_string(value);
                    temp.append(str);
                    temp.append("->");
                }
                else{
                    int value = path[i];
                    string str = to_string(value);
                    temp.append(str);
                }
            }
            paths.push_back(temp);
            path.pop_back();
            return;
        }
        path.push_back(root->val);
        check(root->left,path,paths);
        check(root->right,path,paths);
        path.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int>path;
        vector<string>paths;
        check(root,path,paths);
        return paths;
    }
};