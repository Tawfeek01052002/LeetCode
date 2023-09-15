//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
std::unordered_map<int,int> m;
void mapping(int inorder[],int n){
        for(int i=0;i<n;i++){
            m[inorder[i]]=i;
        }
}
Node *buildTreeFromInOrderAndPostorder(int inorder[], int postorder[], int size, int &postIndex, int inorderStart, int inorderEnd)
{
    // Base case
    if (postIndex < 0 || inorderStart > inorderEnd)
    {
        return NULL;
    }

    // Create node
    int ele = postorder[postIndex--];

    Node *root = new Node(ele);

    // find Position in inorder array
    int pos = m[ele];

    // recursive call
    root->right = buildTreeFromInOrderAndPostorder(inorder, postorder, size, postIndex, pos + 1, inorderEnd);
    root->left = buildTreeFromInOrderAndPostorder(inorder, postorder, size, postIndex, inorderStart, pos - 1);
    
    return root;
}
Node *buildTree(int in[], int post[], int n) {
    mapping(in,n);
    int postIndex = n - 1;
    int inorderStart = 0;
    int inorderEnd = n - 1;
    return buildTreeFromInOrderAndPostorder(in, post, n, postIndex, inorderStart, inorderEnd);
}
