/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        //Base case
        if(root==NULL){
            return NULL;
        }
        
        //check that node == p || node== q (data)
        if(root->val == p->val){
            return p;
        }
        if(root->val == q->val){
           return q; 
        }
        
        //both node may be on left subtree
        TreeNode* leftTree=lowestCommonAncestor(root->left,p,q);
        
        //both node may be on right subtree
        TreeNode* rightTree=lowestCommonAncestor(root->right,p,q);
        
        //check that node is present on one the side based on that returning the value
        if(leftTree==NULL && rightTree==NULL){
            return NULL;
        }
        else if(leftTree==NULL &&  rightTree!=NULL){
            return rightTree;
        }
        else if(leftTree!=NULL && rightTree==NULL){
            return leftTree;
        }
        else{
            return root;
        }
    }
};