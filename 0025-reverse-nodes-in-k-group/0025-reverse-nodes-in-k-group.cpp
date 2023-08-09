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
    int getLength(ListNode* head){
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        return count;
    }
    ListNode* reverseK(ListNode* head,int k){
        if(k==1){
            return head;
        }
        if(head==NULL){
            return head;
        }
        int len=getLength(head);
        if(k>len){
            return head;
        }
        int i=0;
        ListNode * prev=NULL;
        ListNode * curr=head;
        ListNode * forward=curr->next;
        while(forward !=NULL && i<k){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            i++;
        }
        
        if(forward!=NULL){
            head->next=reverseK(forward,k);   
        }
        
        return prev;
        
        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        return reverseK(head,k);
    }
};