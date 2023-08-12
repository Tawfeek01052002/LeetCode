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
    ListNode *getIntersectionNode(ListNode *&headA, ListNode *&headB) {
        ListNode* a=headA;
        ListNode* b=headB;
        while(a->next!=NULL && b->next!=NULL){
            if(a==b){
                return a;
            }
            a=a->next;
            b=b->next;
        }
        //b LL is bigger  find diff
        if(a->next==NULL){
            int diff=0;
            while(b->next!=NULL){
                diff++;
                b=b->next;
            }
            a=headA;
            b=headB;
            while(diff--){
                b=b->next;
            }
        }
        else{  // a LL is bigger find diff
            int diff=0;
            while(a->next!=NULL){
                diff++;
                a=a->next;
            }
            a=headA;
            b=headB;
            while(diff--){
                a=a->next;
            }
        }
        //after headA and headB of same lenght
        while(a!=NULL && b!=NULL){
            if(a==b){
                return a;
            }
            a=a->next;
            b=b->next;
        }
        return NULL;
    }
};