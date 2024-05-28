/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL||head->next==NULL){
            return NULL;
        }
        ListNode*slow=head,*fast=head;
        do{
            if(fast==NULL||fast->next==NULL){
                break;
            }
            slow=slow->next;
            fast=fast->next->next;
        }while(slow!=fast);
        if(slow!=fast){
            return NULL;
        }
        ListNode*st=head;
        while(st!=slow){
            st=st->next;
            slow=slow->next;
        }
        return slow;
    }
};