//1171. Remove Zero Sum Consecutive Nodes from Linked List
//Linked List Medium leetcode

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
    ListNode* removeZeroSumSublists(ListNode* head) {
        map<int,ListNode*>mp;
        map<int,int>indexes;
        
        int sum =0;
        int idx =0;
        
        ListNode*temp = head;
        
        mp[0] = NULL;
        indexes[0] = idx;
        
        while(temp!=NULL){
            
            sum+= temp->val;
            idx++;
            
            if(mp.find(sum)==mp.end()){
                mp[sum]= temp;
                indexes[sum]=idx;
            }
            else{
                ListNode*prev= mp[sum];
                if(prev==NULL){
                    head= temp->next;
                }
                else{
                    prev->next = temp->next;
                }
                int start = indexes[sum]+1;
                int end = idx;
                for(auto x: indexes){
                    if(x.second>=start && x.second<=end){
                        mp.erase(x.first);
                    }
                }
            }
            temp = temp->next;
        }
        return head;
    }
};