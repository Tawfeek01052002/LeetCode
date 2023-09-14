//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    int getPosi(int inorder[], int data,int inorderStart, int inorderEnd)
    {
    
        for (int i =inorderStart ; i <=inorderEnd; i++)
        {
            if (inorder[i] == data)
            {
                return i;
            }
        }
        return -1;
    }
    Node *buildTreeFromInOrderAndPreorder(int inorder[], int preorder[], int& size, int& preIndex, int inorderStart, int inorderEnd)
    {
        // Base case
        if (preIndex >= size || inorderStart > inorderEnd)
        {
            return NULL;
        }
    
        // Create node
        int ele = preorder[preIndex++];
    
        Node *root = new Node(ele);
    
        //find Position in inorder array
        int pos = getPosi(inorder, ele,inorderStart,inorderEnd);
    
        //recursive call 
        root->left = buildTreeFromInOrderAndPreorder(inorder, preorder, size, preIndex, inorderStart, pos - 1);
        root->right = buildTreeFromInOrderAndPreorder(inorder, preorder, size, preIndex, pos + 1, inorderEnd);
    
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int preIndex=0;
        int inorderStart=0;
        int inorderEnd=n-1;
        return buildTreeFromInOrderAndPreorder(in,pre,n,preIndex,inorderStart,inorderEnd);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends