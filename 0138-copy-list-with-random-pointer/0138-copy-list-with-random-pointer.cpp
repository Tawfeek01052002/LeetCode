/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* helper(Node* head,unordered_map<Node*,Node*>& mapping){
        if(head==NULL){
            return NULL;
        }
        Node* newNode=new Node(head->val);
        mapping[head]=newNode;
        newNode->next=helper(head->next,mapping);
        
        if(head->random!=NULL){
            newNode->random=mapping[head->random];
        }
        else{
            newNode->random=NULL;
        }
        return newNode;
    }
    Node* copyRandomList(Node* head) {
        //mapping of old node with new node
        unordered_map<Node*,Node*> mapping;
        Node* newhead=helper(head,mapping);
        return newhead;
    }
};