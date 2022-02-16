//328. Odd Even Linked List
//LinkedList Medium Leetcode

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
    ListNode* oddEvenList(ListNode* head) {
        ListNode*odd=NULL;
        ListNode*temp = NULL;
        ListNode*even = NULL;
        ListNode*curr = head;
        int idx =1;
        while(curr!=NULL){
            if(idx%2!=0){
                if(odd==NULL){
                    odd = new ListNode(curr->val);
                }
                else{
                    temp = odd;
                    while(temp->next!=NULL){
                        temp=temp->next;
                    }
                    temp->next = new ListNode(curr->val);
                }
            }
            else if(idx%2==0){
                if(even ==NULL){
                    even = new ListNode(curr->val);
                }
                else {
                  temp = even;
                    while(temp->next!=NULL){
                        temp = temp ->next;
                    }
                    temp->next = new ListNode(curr->val);
                }
            }
            idx++;
            curr= curr->next;
        }
        ListNode*temp1 = odd;
        if(temp1!=NULL){
            while(temp1->next!=NULL){
                temp1= temp1->next;
            }
            temp1->next =even;
            return odd;
        }
        return even;
    
    }
};