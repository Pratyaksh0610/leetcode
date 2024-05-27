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
    ListNode*revList(ListNode*l){
        if(l==NULL||l->next==NULL) return l;
        ListNode*prev,*curr,*fut;
        prev=NULL;
        curr=l;
        fut=l->next;
        while(curr){
            fut=curr->next;
            curr->next=prev;
            prev=curr;
            curr=fut;
        }
        return prev;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*t1=(l1);
        ListNode*t2=(l2);
        ListNode*temp=NULL;
        while(t1){
            cout<<t1->val<<" ";
            t1=t1->next;
        }
        t1=l1;
        int carry=0;
        while(t1&&t2){
            int sum=t1->val+t2->val+carry;
            t2=t2->next;
            if(sum>9){
                carry=1;
                sum=sum-10;
            }
            else{
                carry=0;
            }
            if(temp==NULL){
                temp=t1;
                t1=t1->next;
                temp->val=sum;
                temp->next=NULL;
            }
            else{
                temp->next=t1;
                t1=t1->next;
                temp=temp->next;
                temp->val=sum;
                temp->next=NULL;
            }
        }
        while(t1){
            int sum=t1->val+carry;
            if(sum>9){
                carry=1;
                sum=sum-10;
            }
            else{
                carry=0;
            }
            if(temp==NULL){
                temp=t1;
                t1=t1->next;
                temp->val=sum;
                temp->next=NULL;
            }
            else{
                temp->next=t1;
                t1=t1->next;
                temp=temp->next;
                temp->val=sum;
                temp->next=NULL;
            }
        }
        while(t2){
            int sum=t2->val+carry;
            if(sum>9){
                carry=1;
                sum=sum-10;
            }
            else{
                carry=0;
            }
            if(temp==NULL){
                temp=t2;
                t2=t2->next;
                temp->val=sum;
                temp->next=NULL;
            }
            else{
                temp->next=t2;
                t2=t2->next;
                temp=temp->next;
                temp->val=sum;
                temp->next=NULL;
            }
        }
        if(carry){
            temp->next=new ListNode(1);
            temp=temp->next;
        }
        return l1;
    }
};