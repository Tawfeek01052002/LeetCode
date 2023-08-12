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
    void merge(ListNode*& list1, ListNode*& list2,ListNode*& anstail){
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
    ListNode* mergeTwoLists(ListNode*& list1, ListNode* &list2) {
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
    ListNode* findMid(ListNode*& head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        //break LL in two halves using mid node
        ListNode * mid=findMid(head);
        ListNode* left=head;
        ListNode* right=mid->next;
        mid->next=NULL;
        
        left=sortList(left);
        right=sortList(right);
        
        ListNode* merged= mergeTwoLists(left,right);
        return merged;
    }
};