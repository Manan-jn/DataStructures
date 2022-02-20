//2095. Delete the Middle Node of a Linked List
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
    ListNode*middleNode(ListNode*head){
        ListNode*slow = head;
        ListNode*fast = head;
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* deleteMiddle(ListNode* head) {
        ListNode*mid = middleNode(head);
        if(head==NULL || mid ==NULL){
            return head;
        }
        if(mid == head){
            return NULL;
        }
        ListNode*prev = NULL;
        ListNode*temp = head;
        while(temp!=mid){
            prev = temp;
            temp = temp->next;
        }
        if(temp!=NULL){
            prev->next = temp->next;
        }
        delete(temp);
        return head;
    }
};