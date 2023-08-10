//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node *reverseList(Node *head)
    {
        Node *curr = head;
        Node *prev = NULL;
        Node *forward = curr->next;
    
        while (curr != NULL)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    Node* addOne(Node *head) 
    {
        head = reverseList(head);
        Node *ans = new Node(-1);
        Node *anstail = ans;
        int carry = 0;
        Node *l1 = head;
        while (l1 != NULL)
        {
    
            int left, right;
            left = l1->data;
            if (l1 == head)
                right = 1;
            else
                right = 0;
            int data = left + right + carry;
            carry = data / 10;
            Node *newNode = new Node(data % 10);
            anstail->next = newNode;
            anstail = newNode;
            l1 = l1->next;
        }
        if (carry != 0)
        {
            anstail->next = new Node(carry % 10);
            carry = carry / 10;
            if (carry != 0)
                anstail->next = new Node(carry % 10);
        }
        ans = reverseList(ans->next);
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends