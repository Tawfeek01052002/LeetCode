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
        
        
        //base Case
        if(root==NULL){
            return NULL;
        }
        
        //check that curr node is p  or q
        if(p->val==root->val){
            return p;
        }
        
        if(q->val==root->val){
            return q;
        }
        
        TreeNode* leftAns=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightAns=lowestCommonAncestor(root->right,p,q);
        
        if(leftAns==NULL && rightAns==NULL){
            return NULL;
        }
        else if(leftAns!=NULL && rightAns==NULL){
            return leftAns;
        }
        else if(leftAns==NULL && rightAns!=NULL){
            return rightAns;
        }
        else{
            return root;
        }
        return NULL; 
    }
};