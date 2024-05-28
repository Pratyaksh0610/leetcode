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
    int len(ListNode*head){
        int length=0;
        if(head==NULL) return 0;
        while(head){
            length++;
            head=head->next;
        }
        return length;
    }
    ListNode*rev(ListNode*head){
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode*prev=NULL,*curr=head,*fut=NULL;
        while(curr){
            fut=curr->next;
            curr->next=prev;
            prev=curr;
            curr=fut;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL){
            return true;
        }
        int l=len(head);
        // cout<<l<<endl;
        int h=l/2;
        if(l%2!=0){
            h++;
        }
        ListNode*temp=head;
        while(h>0){
            h--;
            temp=temp->next;
        }
        // cout<<temp->val<<endl;
        temp=rev(temp);
        while(temp&&head){
            if(temp->val!=head->val){
                return false;
            }
            temp=temp->next;
            head=head->next;
        }
        return true;

    }
};