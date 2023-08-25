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
    int heightOfTree(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return max(heightOfTree(root->left),heightOfTree(root->right))+1;
    }
    bool isBalanced(TreeNode* root) {
        
        
        //Base case
        if(root==NULL){
            return true;
        }
        
        //1 Case
        int leftTree=heightOfTree(root->left);
        int rightTree=heightOfTree(root->right);
        
        bool ans=abs(leftTree-rightTree)<=1;
        
        return ans && isBalanced(root->left) && isBalanced(root->right);
    }
};