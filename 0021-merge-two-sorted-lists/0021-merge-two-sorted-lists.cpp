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
    void merge(ListNode* list1, ListNode* list2,ListNode*& anstail){
        while(list1!=NULL && list2!=NULL){
          if(list1->val<=list2->val){
              ListNode* temp=list1;
              list1=list1->next;
              anstail->next=temp;
              anstail=temp;
          }
          else{
              ListNode* temp=list2;
              list2=list2->next;
              anstail->next=temp;
              anstail=temp;
          }
        }
        if(list1!=NULL){
            anstail->next=list1;
            while(anstail!=NULL){
                anstail=anstail->next;
            }
        }
        if(list2!=NULL){
            anstail->next=list2;
            while(anstail!=NULL){
                anstail=anstail->next;
            }
        }
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
        if(list1==NULL && list2==NULL){
            return NULL;
        }
        ListNode* anshead=new ListNode(-1);
        ListNode * anstail=anshead;
        merge(list1,list2,anstail);
        return anshead->next;
    }
};