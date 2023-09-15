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
    TreeNode* buildTreeHelper(vector<int>& inorder,vector<int>& postorder,int& postIndex,int inStart,int inEnd,unordered_map<int,int>& m){
        //Base Case
        if(postIndex<0 || inStart>inEnd){
            return NULL;
        }
        
        int ele=postorder[postIndex--];
        
        TreeNode* root=new TreeNode(ele);
        
        int pos=m[ele];
        
        root->right=buildTreeHelper(inorder,postorder,postIndex,pos+1,inEnd,m);
        
        root->left=buildTreeHelper(inorder,postorder,postIndex,inStart,pos-1,m);
        
        return root;
        
    }
    
    void mapping(unordered_map<int,int>& m,vector<int>& inorder){
            for(int i=0;i<inorder.size();i++){
                m[inorder[i]]=i;
            }
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> m;
        mapping(m,inorder);
        int postIndex=inorder.size()-1;
        int inStart=0;
        int inEnd=inorder.size()-1;
        return buildTreeHelper(inorder,postorder,postIndex,inStart,inEnd,m);
    }
};