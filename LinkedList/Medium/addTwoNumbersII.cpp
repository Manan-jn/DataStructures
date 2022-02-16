//445. Add Two Numbers II
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
        vector<int>list1;
        vector<int>list2;
        ListNode*temp = l1;
        while(temp!=NULL){
            list1.push_back(temp->val);
            temp = temp->next;
        }
        temp = l2;
        while(temp!=NULL){
            list2.push_back(temp->val);
            temp = temp->next;
        }
        if(list1.size()>list2.size()){
            int diff = list1.size() - list2.size();
            for(int i=0;i<diff;i++){
                list2.insert(list2.begin(),0);
            }
        }
        else if(list2.size()> list1.size()){
             int diff = list2.size() - list1.size();
            for(int i=0;i<diff;i++){
                list1.insert(list1.begin(),0);
            }
        }
        int size = list1.size();
        vector<int>res;
        int power = 0;
        cout<<list1.size()<<endl;
        if(list1.size()>1){
            for(int i=list1.size()-1;i>=0;i--){
                int sum = list1[i]+list2[i];                                                   res.push_back((sum%10+power)%10);
                power = (sum+power)/10;
                  if(i==0 && power!=0){
                    res.push_back(power);
                }
            }
        }
        else{
            if(list1[0]+list2[0]>=10){
                res.push_back((list1[0]+list2[0])%10);
                res.push_back((list1[0]+list2[0])/10);
            }
            else{
                res.push_back(list1[0]+list2[0]);
            }
        }
        reverse(res.begin(),res.end());
        ListNode*ans =NULL;
        for(int i=0;i<res.size();i++){
            if(ans ==NULL){
                ans = new ListNode(res[i]);
            }
            else{
                ListNode*temp = ans;
                while(temp->next!=NULL){
                    temp= temp->next;
                }
                temp->next = new ListNode(res[i]);
            }
        }
        return ans;
    }
};