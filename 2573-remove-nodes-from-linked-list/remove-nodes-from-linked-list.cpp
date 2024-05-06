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
    private:
    ListNode* reverse(ListNode*head){
        if(!head) return NULL;
        ListNode*prev=NULL;
        ListNode*curr=head;
        ListNode*fut=NULL;
        while(curr){
            fut=curr->next;
            curr->next=prev;
            prev=curr;
            curr=fut;
        }
        return prev;
    }
public:
    ListNode* removeNodes(ListNode* head) {
        if(!head) return NULL;
        ListNode* nh=reverse(head);
        ListNode*temp=nh;
        ListNode*nst=temp;
        ListNode*net=nst;
        int val=temp->val;
        temp=temp->next;
        while(temp){
            if(temp->val>=val){
                net->next=temp;
                net=temp;
                val=temp->val;
            }
            temp=temp->next;
        }
        net->next=NULL;
        return reverse(nst);

    }
};