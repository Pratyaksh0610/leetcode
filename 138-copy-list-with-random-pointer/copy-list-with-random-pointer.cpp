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
        Node* temp=head;
        if(!head) return NULL;
        while(temp){
            Node*fut = temp->next;
            temp->next= new Node(temp->val);
            temp->next->next=fut;
            temp=fut;
        }
        temp=head;
        Node*nhead=NULL;
        Node*ntail=NULL;

        while(temp){
            Node* copyTemp=temp->next;
            Node*fut=temp->next->next;
            // if(!nhead){
            //     nhead=copyTemp;
            //     ntail=copyTemp;
            // }
            // else{
            //     ntail->next=copyTemp;
            //     ntail=ntail->next;
            // }
            Node*tempRandom=temp->random;
            if(tempRandom){
                copyTemp->random=tempRandom->next;
            }
            // temp->next=fut;
            temp=fut;
        }
        temp=head;
        while(temp){
            Node*fut= temp->next->next;
            Node* copyTemp=temp->next;
            if(!nhead){
                nhead=copyTemp;
                ntail=copyTemp;
            }
            else{
                ntail->next=copyTemp;
                ntail=ntail->next;
            }
            temp->next=fut;
            temp=fut;
        }
        return nhead;
    }
};