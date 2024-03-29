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
    //Using Tortoise Algorithm
    bool hasCycle(ListNode *head) {
        if(head==NULL){
            return false;
        }
        ListNode* slow=head;
        ListNode* fast=head->next;
        
        while(fast!=NULL && slow!=NULL){
            if(slow==fast){
                return true;
            }
            slow=slow->next;
            if(fast->next==NULL){
                return false;
            }
            fast=fast->next->next;
        }
        return false;
    }
};