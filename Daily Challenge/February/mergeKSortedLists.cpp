//23. Merge k Sorted Lists
//5th Feb

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
    ListNode*midpoint(ListNode*head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode*slow = head;
        ListNode*fast = head->next;
   
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode*merge(ListNode*a,ListNode*b){
        if(a==NULL){
            return b;
        }
        if(b==NULL){
            return a;
        }
        ListNode*c;
        if(a->val < b->val){
            c = a;
            c->next = merge(a->next,b);
        }
        else{
            c= b;
            c->next = merge(a,b->next);
        }
        return c;
    }
    ListNode*mergeSort(ListNode*head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        ListNode*mid = midpoint(head);
        ListNode*a = head;
        ListNode*b = mid->next;
        mid->next = NULL;
        
        a = mergeSort(a);
        b = mergeSort(b);
        
        ListNode*c = merge(a,b);
        return c;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        ListNode*temp = NULL;
        ListNode*head = NULL;
        for(int i=0;i<k;i++){
            ListNode*newHead = lists[i];
            if(temp!=NULL){
                temp->next = newHead;
            }
            while(newHead!=NULL){
                temp = newHead;
                newHead= newHead->next;
            }
        }
        if(k>0){
            for(int i=0;i<k;i++){
                if(lists[i]!=NULL){
                    head = lists[i];
                    break;
                }
            }
        }
        if(head!=NULL){
            return mergeSort(head);
        }
        return NULL;
    }
};