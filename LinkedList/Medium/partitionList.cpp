//86. Partition List
// Leetcode Medium LinkedList

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
    ListNode* partition(ListNode* head, int x) {
        ListNode*temp = head;
        ListNode*p = NULL;
        ListNode*prev = NULL;
        while(temp!=NULL){
            if(temp->val<x){
                if(temp==head){
                    prev = temp;
                }
                else{
                    if(prev==NULL){
                        
                        if(p!=NULL){
                            p->next = temp->next;
                        }
                        
                        ListNode*t = head;
                        head= temp;
                        temp->next = t;
                    }
                    else{
                        if(p!=NULL){
                            p->next = temp->next;
                        }
                        
                        ListNode*t = prev->next;
                        prev->next = temp;
                        temp->next = t;
                    }
                }
                prev= temp;
            }
            p = temp;
            temp=temp->next;
        }
        return head;
    }
};