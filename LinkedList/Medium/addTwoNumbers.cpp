//2. Add Two Numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int>n1;
        vector<int>n2;
        while(l1!=NULL){
            n1.push_back(l1->val);
            l1= l1->next;
        }
        while(l2!=NULL){
            n2.push_back(l2->val);
            l2= l2->next;
        }
        int carry =0;
        vector<int>res;
        int j=0;
        int i=0;
        for(i;i<n1.size();i++){
            if(j<n2.size()){
                int sum = (n1[i]+n2[j])%10;
                res.push_back((sum+carry)%10);
                carry = (n1[i]+n2[j]+carry)/10;
                j++;
            }
            else{
                break;
            }
        }
        while(i<n1.size()){
            int sum = (n1[i]+carry)%10;
            res.push_back(sum);
            carry = (n1[i]+carry)/10;
            i++;
        }
        while(j<n2.size()){
            int sum = (n2[j]+carry)%10;
            res.push_back(sum);
            carry = (n2[j]+carry)/10;
            j++;
        } 
        if(carry){
            res.push_back(1);
        }
        ListNode*head = NULL;
        for(int i=res.size()-1;i>=0;i--){
            ListNode*n = new ListNode(res[i]);
            if(head==NULL){
                head = n;
            }
            else{
                n->next = head;
                head=n;
            }
        }
        return head;
    }
};