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
    // ListNode* reversewithCount(ListNode* &head,int& n,int& i){
    //     if(head==NULL){
    //         return NULL;
    //     }
    //     reversewithCount(head->next,n,i);
    //     if(i==n){
    //         if(head->next!=NULL){
    //             head->next=head->next->next;
    //         }
    //     }
    //     i++;
    //     return head;
    // }
    // int getLength(ListNode *head){
    //     int count=0;
    //     while(head!=NULL){
    //         head=head->next;
    //         count++;
    //     }
    //     return count;
    // }
    
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    //     int i=0;
    //     if(n==getLength(head)){
    //         return head->next;
    //     }
    //     return reversewithCount(head,n,i);

    ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;

        return dummy->next;
    }

};