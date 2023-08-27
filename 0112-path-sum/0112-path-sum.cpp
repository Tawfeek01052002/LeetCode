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
    bool Solve(TreeNode* root,int& target,int currSum){
        if(root==NULL){
            return false;
        }
        currSum+=root->val;
        if(root->left==NULL &&  root->right==NULL){
            if(target==currSum){
                return true;
            }
            return false;
        }
        return Solve(root->left,target,currSum) || Solve(root->right,target,currSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int currSum=0;
        return Solve(root,targetSum,currSum);
    }
};