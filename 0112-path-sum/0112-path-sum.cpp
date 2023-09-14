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
    bool Solve(TreeNode* root,int& targetSum, int CurrSum){
        if (root == nullptr) {
            return false;
        }

        CurrSum += root->val;
        if (targetSum == CurrSum && !root->left && !root->right) {
            return true;
        }

        return Solve(root->left, targetSum , CurrSum) || Solve(root->right, targetSum , CurrSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return Solve(root,targetSum,0);
    }
};