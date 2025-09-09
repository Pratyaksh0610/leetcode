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
    ListNode*reverse(ListNode*head){
        if(!head||!head->next) return head;
        ListNode*prev=NULL,*curr=head,*fut=head->next;
        while(curr){
            fut=curr->next;
            curr->next=prev;
            prev=curr;
            curr=fut;
        }
        return prev;
    }
    // ListNode* lenReverse(ListNode* head,int k){
    //     if()
    // }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head||!head->next||k==1) return head;
        ListNode*nhead=NULL;
        ListNode*ntail=NULL;
        ListNode*temp=head;
        while(temp){
            int l=k;//2
            ListNode*curr=temp;//1
            while(curr&&l>1){//1
                curr=curr->next;
                l--;
            }
            if(!curr) break;//2
            ListNode*st=temp,*end=curr->next;
            //st=1,
            curr->next=NULL;
            ListNode*prev=NULL,*c=st,*fut=st->next;
            while(c){
                fut=c->next;
                c->next=prev;
                prev=c;
                c=fut;
            }
            if(nhead==NULL){
                nhead=prev,ntail=st;
            }
            else{
                ntail->next=prev;
                ntail=st;
            }
            ntail->next=end;
            temp=end;
        }
        return nhead;
    }
};