//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        Node *zerohead = new Node(-1);
        Node *zerotail = zerohead;
        Node *onehead = new Node(-1);
        Node *onetail = onehead;
        Node *twohead = new Node(-1);
        Node *twotail = twohead;
    
        Node *curr = head;
        while (curr != NULL)
        {
            Node *temp = curr;
            curr = curr->next;
            temp->next = NULL;
            if (temp->data == 0)
            {
                zerotail->next = temp;
                zerotail = temp;
            }
            else if (temp->data == 1)
            {
                onetail->next = temp;
                onetail = temp;
            }
            else if (temp->data == 2)
            {
                twotail->next = temp;
                twotail = temp;
            }
        }
        // Joining All nodes of zero ,one,two
        // deleting temp-head of zero,one,two
        Node *temp1 = zerohead;
        Node *temp2 = onehead;
        Node *temp3 = twohead;
        zerohead = zerohead->next;
        onehead = onehead->next;
        twohead = twohead->next;
        temp1->next = NULL;
        temp2->next = NULL;
        temp3->next = NULL;
        delete temp1;
        delete temp2;
        delete temp3;
        if (zerohead != NULL)
        {
            if (onehead != NULL)
            {
                zerotail->next = onehead;
                onetail->next = twohead;
            }
            else
            {
                zerotail->next = twohead;
            }
            return zerohead;
        }
        else if (onehead != NULL)
        {
            onetail->next = twohead;
            return onehead;
        }
        else if (twohead != NULL)
        {
            return twohead;
        }
        return NULL;
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends