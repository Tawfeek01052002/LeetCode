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
    ListNode* reverseList(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* forward=curr->next;
        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    int getLength(ListNode*& head){
        int count=0;
        ListNode * temp=head;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        return count;
    }
    ListNode* rotateRight(ListNode*& head, int k) {
       
        /*
        int n=getLength(head);
        if(head==NULL || head->next==NULL || k==0 || k%n==0){
            return head;
        }
        head=reverseList(head);
        
        ListNode * fast=head;
        ListNode* slow=head;
        while(k%n>1){
            fast=fast->next;
            slow=slow->next;
            k--;
        }
        if(fast==NULL){
            return head;
        }
        fast=fast->next;
        slow->next=NULL;
        head=reverseList(head);
        slow=head;
        while(slow->next!=NULL){
            slow=slow->next;
        }
        fast=reverseList(fast);
        slow->next=fast;
        return head;
        */
        
        int n=getLength(head);
        if(head==NULL || head->next==NULL || k==0 || k%n==0){
            return head;
        }
        ListNode* temp=head;
        k=k%n;
        int newLastNodePos=n-k-1;
        int i=0;
        while(i<newLastNodePos){
            temp=temp->next;
            i++;
        }
        ListNode* nexthead=temp->next;
        temp->next=NULL;
        temp=nexthead;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=head;
        return nexthead;
        
    }
};