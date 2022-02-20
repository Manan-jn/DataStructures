//143. Reorder List
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
    ListNode*midPoint(ListNode*head){
        ListNode*slow = head;
        ListNode*fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    void reorderList(ListNode* head) {
        ListNode*mid = midPoint(head);

        stack<ListNode*>last;
        ListNode*temp = mid->next;
        mid->next = NULL;
        while(temp!=NULL){
            last.push(temp);
            temp=temp->next;
        }
        
        temp = head;
        while(temp!=NULL){
            if(last.empty()){
                break;
            }
            ListNode*curr = last.top();
            ListNode*t = temp->next;
            temp->next = curr;
            curr->next = t;
            last.pop();
            if(temp->next!=NULL){
                temp = temp->next->next;
            }
            else{
                break;
            }
        }
        return;
    }
};