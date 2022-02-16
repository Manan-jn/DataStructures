//1721. Swapping Nodes in a Linked List
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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode*temp = head;
        int count =1;
        ListNode*first = NULL;
        while(temp!=NULL){
            if(count==k){
                first = temp;
            }
            count++;
            temp = temp->next;
          
        }
        temp = head;
        ListNode*second = NULL;
        int pos =1;
        while(temp!=NULL){
            if(pos == count - k){
                second = temp;
                break;
            }
            pos++;
            temp = temp->next;
        }
        if(second!=NULL && first!=NULL){
            swap(second->val,first->val);
        }
        return head;
    }
};