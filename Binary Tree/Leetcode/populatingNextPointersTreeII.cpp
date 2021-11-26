//117. Populating Next Right Pointers in Each Node II
//Leetcode Medium Binary Tree
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*>q;
        if(root!=NULL){
            q.push(root);
            q.push(NULL);
        }
        while(!q.empty()){
            Node*f = q.front();
            if(f==NULL){
                q.pop();
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                q.pop();
                Node*temp = q.front();
                f->next = temp;
                if(f->left){
                    q.push(f->left);
                }
                if(f->right){
                    q.push(f->right);
                }
            }
        }
        return root;
    }
};