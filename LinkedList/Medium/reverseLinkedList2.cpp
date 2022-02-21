//92. Reverse Linked List II
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
    ListNode*reverse(ListNode*head,ListNode*tail,ListNode*next){
        if(head==NULL){
            return NULL;
        }
        ListNode*c = head;
        ListNode*p= next;
        while(c!=next){
            ListNode*temp = c->next;
            c->next = p;
            p=c;
            c=temp;
        }
        head= p;
        return head;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
            int count =1;
            ListNode*temp = head;
            ListNode*p=NULL;
            ListNode*prev = NULL;
            ListNode*next;
        
            if(left==right){
                return head;
            }
        
            ListNode*newHead = NULL;
            ListNode*tail = NULL;
        
            while(temp!=NULL){
                if(count == left){
                    prev= p;
                    newHead= temp;
                }
                else if(count == right){
                    tail = temp;
                    next = temp->next;
                }
                
                p = temp;
                temp = temp->next;
                count++;
            }
            ListNode*t = reverse(newHead,tail,next);

            if(prev==NULL){
                  head = t;
            }
            else{
                prev->next = t;
            }
            return head;
    }
};