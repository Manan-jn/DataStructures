//1019. Next Greater Node In Linked List
//Leetcode Medium LinkedList

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
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        int count =1;
        ListNode*temp = head;
        while(temp!=NULL){
            count++;
            temp= temp->next;
        }
        stack<pair<int,int>>myStack;
        vector<int>res(count-1,0);
        
        temp = head;
        int idx =0;
        while(temp!=NULL){
            if(!myStack.empty() && temp->val > myStack.top().first){
                while(!myStack.empty() && temp->val > myStack.top().first){
                    pair<int,int>found = myStack.top();
                    res[found.second] = temp->val;
                    myStack.pop();
                }
            }
            myStack.push({temp->val,idx});
            idx++;
            temp = temp->next;
        }
  
        while(!myStack.empty()){
            pair<int,int>found = myStack.top();
            res[found.second]=0;
            myStack.pop();
        }
        return res;
    }
};