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
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*nhead=NULL,*ntail=NULL;
        while(list1&&list2){
            int v1=list1->val;
            int v2=list2->val;
            if(v1<=v2){
                if(!nhead){
                    nhead=list1,ntail=list1;
                }
                else{   
                    ntail->next=list1;
                    ntail=ntail->next;
                }
                list1=list1->next;
                ntail->next=NULL;
            }
            else{
                if(!nhead){
                    nhead=list2,ntail=list2;
                }
                else{   
                    ntail->next=list2;
                    ntail=ntail->next;
                }
                list2=list2->next;
                ntail->next=NULL;
            }
        }
        while(list1){
            if(!nhead){
                nhead=list1;
                ntail=list1;
            }
            else{
                ntail->next=list1;
                ntail=ntail->next;
            }
            list1=list1->next;
            ntail->next=NULL;
        }
        while(list2){
            if(!nhead){
                nhead=list2;
                ntail=list2;
            }
            else{
                ntail->next=list2;
                ntail=ntail->next;
            }
            list2=list2->next;
            ntail->next=NULL;
        }
        return nhead;
    }
};