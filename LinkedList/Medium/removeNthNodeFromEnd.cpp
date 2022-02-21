//19. Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*slow = head;
        ListNode*temp = head;
        ListNode*fast = head;
        int count =0;
        while(temp!=NULL){
            if(count==n){
                break;
            }
            count++;
            temp= temp->next;
            fast = fast->next;
        }
        ListNode*prev=NULL;
        while(fast!=NULL){
            prev = slow;
            slow = slow->next;
            fast= fast->next;
        }
        if(prev!=NULL){
            prev->next = slow->next;
            delete slow;
        }
        else{
            ListNode*t= slow->next;
            delete slow;
            return t;
        }
        return head;
    }
};