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
    void merge(ListNode* head,ListNode*& anstail){
        ListNode* curr=head;
        while(curr!=NULL){
            int sum=0;
            while(curr!=NULL && curr->val!=0){
                sum+=curr->val;
                curr=curr->next;
            }
            ListNode* newNode=new ListNode(sum);
            anstail->next=newNode;
            anstail=newNode;
            curr=curr->next;
        }
    }
    ListNode* mergeNodes(ListNode* head) {
        ListNode* anshead=new ListNode(-1);
        ListNode* anstail=anshead;
        merge(head->next,anstail);
        return anshead->next;
    }
};