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
    /*
    Node* helper0(Node* head,unordered_map<Node*,Node*>& mapping){
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
    */
    void print(Node* head){
        while(head!=NULL){
            cout<<head->val<<" ";
            head=head->next;
        }
        cout<<endl;
    }
    Node* copyRandomList(Node* head) {
        //mapping of old node with new node
        // unordered_map<Node*,Node*> mapping;
        // Node* newhead=helper0(head,mapping);
        // return newhead;
        
        //without using map
        if(head==NULL){
            return NULL;
        }
        
        //step 1:Clone nodes A->A'->B->B'....
        Node* it=head;
        while(it){
            Node* clonedNode=new Node(it->val);
            clonedNode->next=it->next;
            it->next=clonedNode;
            it=clonedNode->next;
        }
        
        //step 2 :Assigning randoms of new node with the help of old node
        it=head;
        while(it){
            Node* cloneNode =it->next;
            cloneNode->random=it->random!=NULL?it->random->next:NULL;
            it=cloneNode->next;
        }
        print(head);
        
        // step 3: detached A' from A 
        it=head;
        Node* clonedhead=it->next;
        while(it){
            Node* clonedNode=it->next;
            it->next=clonedNode->next;
            if(clonedNode->next){
                clonedNode->next=clonedNode->next->next;
            }
            it = it->next;
        }
        return clonedhead;
    }
};