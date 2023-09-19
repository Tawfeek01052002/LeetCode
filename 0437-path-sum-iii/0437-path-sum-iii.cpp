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
    void Solve(TreeNode* root,int& targetSum, long long CurrSum,long long& ans){
        if (root == nullptr) {
            return;
        }

        CurrSum += root->val;
        if (targetSum == CurrSum) {
            ans+=1;
        }
        Solve(root->left, targetSum , CurrSum,ans);
        Solve(root->right, targetSum , CurrSum,ans);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return 0;
        }
        long long ans=0;
        Solve(root,targetSum,0,ans);
        
        int lsum=pathSum(root->left,targetSum);
        int rsum=pathSum(root->right,targetSum);
        return ans+lsum+rsum;
    }
};