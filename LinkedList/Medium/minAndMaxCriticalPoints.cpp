//2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
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
    int length(ListNode*head){
        if(head==NULL){
            return 0;
        }
        int count=0;
        while(head!=NULL){
            count++;
            head= head->next;
        }
        return count;
    }
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>res;
        
        int count = length(head);
        res.push_back(-1);
        res.push_back(-1);
        if(count<3){
            return res;
        }
        
        int prev = head->val;
        ListNode*temp = head->next;
        int curr = temp->val;
        int next = temp->next->val;
        int dist = 2;
        vector<int>distance;
        
        while(temp!=NULL&&temp->next!=NULL){
            if(curr < next && curr < prev){
                //local minima
                distance.push_back(dist);
            }
            else if(curr > prev && curr> next){
                //local maxima
                distance.push_back(dist);
            }
            
            prev = temp->val;
            temp = temp->next;
            
            if(temp==NULL || temp->next==NULL){
                break;
            }
            
            curr = temp->val;
            next = temp->next->val;
            
            dist++;
        }
        sort(distance.begin(),distance.end());
        
   
        if(distance.size()<2){
            return res;
        }
      
        int minD = INT_MAX;
        res.clear();
        for(int i=0;i<distance.size()-1;i++){
           minD = min(minD,abs(distance[i]-distance[i+1]));
        }
        
        res.push_back(minD);
        res.push_back(distance[distance.size()-1]- distance[0]);

        return res;
    }
};