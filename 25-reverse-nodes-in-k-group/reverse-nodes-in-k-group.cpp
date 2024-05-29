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
    int len(ListNode*head){
        int ans=0;
        while(head){
            head=head->next;
            ans++;
        }
        return ans;
    }
    ListNode*rev(ListNode*head){
        ListNode*prev,*curr,*fut;
        prev=NULL;
        curr=head;
        while(curr){
            fut=curr->next;
            curr->next=prev;
            prev=curr;
            curr=fut;
        }
        return prev;
    }
    ListNode*fun(ListNode*head,int groups,int k){
        if(!head||groups==0){
            return head;
        }
        ListNode*st=head;
        ListNode*end=head;
        int kk=k;
        while(k>0){
            end=end->next;
            k--;
        }
        ListNode*fut=end->next;
        end->next=NULL;
        ListNode*future=fun(fut,groups-1,kk);
        // cout<<fut->val<<" "<<st->val<<endl;
        ListNode*nhead=rev(st);
        st->next=future;
        return nhead;

    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int length=len(head);
        int groups=length/k;
        // cout<<length<<" "<<groups<<endl;
        return fun(head,groups,k-1);
        // return head;
    }
};