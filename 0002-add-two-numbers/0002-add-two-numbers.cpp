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
    int solve(ListNode* &l1, ListNode* &l2,ListNode*& anstail,int carry){
        if(l1==NULL &&  l2==NULL){
            return carry;
        }
        int left,right;
        if(l1!=NULL){
            left=l1->val;
        }
        else
            left=0;
        if(l2!=NULL){
           right=l2->val;
        }
        else
            right=0;
        
        int data=left+right+carry;
        carry=data/10;
        ListNode* newNode=new ListNode(data%10);
        anstail->next=newNode;
        anstail=newNode;
        l1= l1!=NULL?l1->next:NULL;
        l2= l2!=NULL?l2->next:NULL;
        return solve(l1,l2,anstail,carry);
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * ans=new ListNode(-1);
        ListNode* anstail=ans;
        int carry=0;
        carry = solve(l1,l2,anstail,carry);
        if(carry!=0){
            anstail->next=new ListNode(carry%10);
            carry=carry/10;
            if(carry!=0)
                anstail->next=new ListNode(carry%10);
            
        }
        return ans->next;
    }
};