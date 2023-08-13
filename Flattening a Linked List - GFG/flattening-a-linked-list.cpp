//{ Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}

// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

Node* merge(Node* list1 ,Node* list2){
    Node* anshead=new Node(-1);
    Node* anstail=anshead;
    while(list1!=NULL && list2!=NULL){
          if(list1->data<=list2->data){
              Node* temp=list1;
              list1=list1->bottom;
              anstail->bottom=temp;
              temp->bottom = NULL; 
              anstail=temp;
          }
          else{
              Node* temp=list2;
              list2=list2->bottom;
              anstail->bottom=temp;
              temp->bottom = NULL; 
              anstail=temp;
          }
        }
        if(list1!=NULL){
            anstail->bottom=list1;
            while(anstail->bottom!=NULL){
                anstail=anstail->bottom;
            }
        }
        if(list2!=NULL){
            anstail->bottom=list2;
        }
        return anshead->bottom;
}

/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
   // Your code here
   if(root==NULL || root->next==NULL){
       return root;
   }
   while(root->next!=NULL){
       Node* first=root;
       Node* second=root->next;
       Node* forward=second->next;
       first->next=NULL;
       second->next=NULL;
       first=merge(first,second);
       root=first;
       root->next=forward;
   }
   return root;
}

