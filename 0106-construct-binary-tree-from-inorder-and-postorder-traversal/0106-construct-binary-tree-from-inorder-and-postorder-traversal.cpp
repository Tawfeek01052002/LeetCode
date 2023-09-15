/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int found(vector<int>& inorder,int data,int inStart,int inEnd){
        for(int i=inStart;i<=inEnd;i++){
            if(inorder[i]==data){
                return i;
            }
        }
        return -1;
    }
    TreeNode* buildTreeHelper(vector<int>& inorder,vector<int>& postorder,int& postIndex,int inStart,int inEnd){
        //Base Case
        if(postIndex<0 || inStart>inEnd){
            return NULL;
        }
        
        int ele=postorder[postIndex--];
        
        TreeNode* root=new TreeNode(ele);
        
        int pos=found(inorder,ele,inStart,inEnd);
        
        root->right=buildTreeHelper(inorder,postorder,postIndex,pos+1,inEnd);
        
        root->left=buildTreeHelper(inorder,postorder,postIndex,inStart,pos-1);
        
        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIndex=inorder.size()-1;
        int inStart=0;
        int inEnd=inorder.size()-1;
        return buildTreeHelper(inorder,postorder,postIndex,inStart,inEnd);
    }
};