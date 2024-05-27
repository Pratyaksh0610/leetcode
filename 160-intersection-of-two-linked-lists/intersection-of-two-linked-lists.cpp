/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int len(ListNode*l){
        if(l==NULL){
            return 0;
        }
        int val=0;
        while(l){
            l=l->next;
            val++;
        }
        return val;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1=len(headA),len2=len(headB);
        int diff=len1-len2;
        while(diff>0){
            headA=headA->next;
            diff--;
        }
        while(diff<0){
            headB=headB->next;
            diff++;
        }
        while(headA&&headB){
            if(headA==headB){
                return headA;
            }
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
    }
};