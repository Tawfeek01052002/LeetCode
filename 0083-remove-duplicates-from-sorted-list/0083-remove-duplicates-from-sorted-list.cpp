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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * curr=head;
        ListNode * next=head;
        while(next!=NULL){
            while(next!=NULL && curr->val==next->val){
                next=next->next;
            }
            curr->next=next;
            curr=next;
        }
        return head;
    }
};