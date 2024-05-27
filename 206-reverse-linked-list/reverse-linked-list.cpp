#define pi pair<ListNode*,ListNode*>
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
    pi fun(ListNode*head){
        if(head->next==NULL){
            return {head,head};
        }
        pi fut=fun(head->next);
        fut.second->next=head;
        head->next=NULL;
        return {fut.first,head};
        //head,curr;
    }
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        pi ans=fun(head);
        return ans.first;
    }
};