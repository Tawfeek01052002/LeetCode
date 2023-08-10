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
        
        // without deleting the nodes
        // ListNode * curr=head;
        // ListNode * next=head;
        // while(next!=NULL){
        //     while(next!=NULL && curr->val==next->val){
        //         next=next->next;
        //     }
        //     curr->next=next;
        //     curr=next;
        // }
        // return head;
        
        
        //if we want to delete the nodes then follow below code
        if (head == NULL)
        {
            cout << "LL is empty" << endl;
            return head;
        }
        if (head->next == NULL)
        {
            cout << "LL has only one element" << endl;
            return head;
        }
        ListNode *curr = head;
        ListNode *forward = curr->next;
        while (curr != NULL && curr->next != NULL)
        {
            ListNode *forward = curr->next;
            while (forward != NULL && curr->val == forward->val)
            {
                ListNode *temp = forward;
                forward = forward->next;
                temp->next = NULL;
                delete temp;
            }
            curr->next = forward;
            curr = curr->next;
        }
        return head;
    }
};