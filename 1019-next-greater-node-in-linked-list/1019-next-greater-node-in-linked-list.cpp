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
    vector<int> nextLargerNodes(ListNode* head) {
        head=reverseList(head);
        vector<int> ans;
        stack<ListNode*> s;
        ListNode* temp=head;
        while(temp!=NULL){
            while(!s.empty() && s.top()->val<=temp->val){
                s.pop();
            }
            if(s.empty()){
                ans.push_back(0);
            }
            else{
                ans.push_back(s.top()->val);    
            }
            s.push(temp);
            temp=temp->next;
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};