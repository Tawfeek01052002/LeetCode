//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    struct Node* reverseList(struct Node* head){

        Node* curr=head;
        Node* forward=curr->next;
        Node* prev=NULL;
        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* l1, struct Node* l2)
    {
        /* Recursion solution
    node *ans = new node(-1);
    node *anstail = ans;
    int carry = 0;
    carry = solve(l1, l2, anstail, carry);
    if (carry != 0)
    {
        anstail->next = new node(carry % 10);
        carry = carry / 10;
        if (carry != 0)
            anstail->next = new node(carry % 10);
    }
    return ans->next;
    */

        //  without recursion
        l1=reverseList(l1);
        l2=reverseList(l2);
        Node *ans = new Node(-1);
        Node *anstail = ans;
        int carry = 0;
        while (l1 != NULL || l2 != NULL)
        {
    
            int left, right;
            if (l1 != NULL)
            {
                left = l1->data;
            }
            else
                left = 0;
            if (l2 != NULL)
            {
                right = l2->data;
            }
            else
                right = 0;
            int data = left + right + carry;
            carry = data / 10;
            Node *newNode = new Node(data % 10);
            anstail->next = newNode;
            anstail = newNode;
            l1 = (l1 != NULL) ? l1->next : NULL;
            l2 = (l2 != NULL) ? l2->next : NULL;
        }
        if (carry != 0)
        {
            anstail->next = new Node(carry % 10);
            carry = carry / 10;
            if (carry != 0)
                anstail->next = new Node(carry % 10);
        }
        
        ans= reverseList(ans->next);
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
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends