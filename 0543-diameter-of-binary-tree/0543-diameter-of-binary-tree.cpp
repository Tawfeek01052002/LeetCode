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
    int D=0;
    int heightOfTree(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        
        int lh=heightOfTree(root->left);
        
        int rh=heightOfTree(root->right);
        
        int currD=lh+rh;
        
        D=max(D,currD);
        
        return max(lh,rh)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        heightOfTree(root);
        return D;
    }
};