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
    ListNode* reverse(ListNode*head,ListNode* &ans){
        if(!head->next){
            ans=head;
            return head;
        }
        ListNode*fut= reverse(head->next,ans);
        fut->next=head;
        head->next=NULL;
        return head;
    }
public:
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next){
            return head;
        }
        ListNode* rec=NULL;
        reverse(head,rec);
        return rec;
    }
};