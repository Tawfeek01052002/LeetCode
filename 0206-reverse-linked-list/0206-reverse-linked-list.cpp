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
    ListNode* reverseListHelper(ListNode * &head,ListNode*& curr,ListNode*& prev){
        //Base case
        if(curr==NULL){
            return prev;
        }
        ListNode* forward=curr->next;
        curr->next=prev;
        
        //recursive call
        return reverseListHelper(head,forward,curr);
        
    }
    ListNode* reverseList(ListNode* head) {
        if(head==NULL ||head->next==NULL){
            return head;
        }
        ListNode *prev= NULL;
        ListNode *curr= head;
        return reverseListHelper(head,curr,prev);
    }
};