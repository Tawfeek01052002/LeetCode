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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans={-1,-1};
        ListNode* prev=head;
        if(prev==NULL){
            return ans;
        }
        ListNode* curr=head->next;
        if(curr==NULL) return ans;
        ListNode* next=head->next->next;
        if(next==NULL) return ans;
        
        int firstCP=-1;
        int lastCP=-1;
        int minDist=INT_MAX;
        int i=0;
        
        while(next!=NULL){
            bool isCP=((curr->val > prev->val && curr->val >next->val)  || (curr->val < prev->val && curr->val <next->val))? true:false;
            
            if(isCP && firstCP==-1){
                firstCP=i;
                lastCP=i;
            }
            else if(isCP){
                minDist=min(minDist,i-lastCP);
                lastCP=i;
            }
            i++;
            prev=prev->next;
            curr=curr->next;
            next=next->next;
        }
        if(lastCP==firstCP){ //only one CP is found
            return ans;
        }
        else{
            ans[0]=minDist;
            ans[1]=lastCP-firstCP;
        }
        return ans;
    }
};