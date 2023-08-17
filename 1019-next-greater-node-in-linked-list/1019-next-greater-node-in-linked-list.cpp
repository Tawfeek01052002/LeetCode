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
    ListNode* reverseList(ListNode*& head){
        
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
    // T.C.=O(n) //S.C.=O(1)(without answer vector)
    vector<int> nextLargerNodes(ListNode* head) {
        
        /* Good Solution (solve by me -Recommended in interview)
        //reversing the list to process previous part
        head=reverseList(head);
        
        //store ans in reverse order
        vector<int> ans;
        
        //use stack to get greater number
        stack<ListNode*> s;
        
        ListNode* temp=head;
        //traversing the list
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
        //reverse ans
        reverse(ans.begin(),ans.end());
        return ans;
        
        */
        
        
         // also recommended if interviewer told that do not modify the LL
        vector<int> ll;
        ListNode *temp = head;
        // copying data into array for processing
        while (temp)
        {
            ll.push_back(temp->val);
            temp = temp->next;
        }

        // creating stack to store indexes
        stack<int> s;

        int n = ll.size();

        // vector to store ans or use ll list created as previous(as below code)
        // vector<int> ans(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (s.empty() || ll[s.top()] >= ll[i])
            {
                s.push(i);
            }
            else
            {
                while (!s.empty() && ll[s.top()] < ll[i])
                {
                    ll[s.top()] = ll[i];
                    s.pop();
                }
                s.push(i);
            }
        }

        while(!s.empty()){
            ll[s.top()]=0;
            s.pop();
        }
        return ll;
    }
};