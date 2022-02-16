//24. Swap Nodes in Pairs
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
    ListNode* swap(ListNode*head, ListNode*curr , ListNode*prev){
        if(curr==NULL){
            return prev;
        }
        if(curr!=NULL && curr->next!=NULL){
            prev->next = swap(head,curr->next->next,curr->next);
        }
        else{
            prev->next = NULL;
        }
        if(prev == head){
            head = curr;
        }
        curr->next = prev;
        return curr;
    }
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        if(head->next!=NULL){
            return swap(head,head->next,head);
        }
        return head;
    }
};