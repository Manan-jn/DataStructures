//142. Linked List Cycle II
// 19th January

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* check(ListNode*head){
        ListNode*slow = head;
        ListNode*fast = head;
        while(slow!=NULL && fast!=NULL &&fast->next!=NULL){
            slow= slow->next;
            fast= fast->next->next;
            if(slow==fast){
                slow= head;
                while(slow!=fast){
                    slow= slow->next;
                    fast= fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode* found = check(head);
        return found;
    }
};