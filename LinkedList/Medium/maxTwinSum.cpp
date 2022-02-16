// 2130. Maximum Twin Sum of a Linked List
//Leetcode Medium Linked lIST

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
    int pairSum(ListNode* head) {
        vector<int>values;
        while(head!=NULL){
            values.push_back(head->val);
            head= head->next;
        }
        int n = values.size();
        int maxSum =0;
        for(int i=0;i<n/2;i++){
            int sum = values[i]+ values[n-i-1];
            maxSum = max(maxSum,sum);
        }
        return maxSum;
    }
};