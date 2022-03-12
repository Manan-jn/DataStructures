//138. Copy List with Random Pointer
//Leetcode Medium LinkedList 

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        vector<Node*>track;
        vector<Node*>orignal;
        if(head==NULL){
            return NULL;
        }
        
        Node*temp = head;
        int i=0;
        while(temp!=NULL){
            Node*newNode = new Node(temp->val);
            if(i>0){
                track[i-1]->next = newNode;
            }
            track.push_back(newNode);
            i++;
            orignal.push_back(temp);
            temp = temp->next;
        }
        temp = head;
        
        int j=0;
        while(temp!=NULL){
            Node*n = temp->random;
            Node*found = NULL;
            for(int i=0;i<orignal.size();i++){
                if(orignal[i]==n){
                    found= track[i];
                    break;
                }
            }
            if(j<track.size()){
                track[j]->random = found;
            }
            j++;
            temp = temp->next;
        }
        return track[0];
    }
};