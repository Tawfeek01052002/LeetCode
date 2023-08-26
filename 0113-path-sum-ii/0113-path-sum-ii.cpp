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
    void Solve(TreeNode* root,int target,int currSum,vector<vector<int>>& ans,vector<int>& arr){
        
        //Base Case
        if(root==NULL){
            return;
        }
                
        if(root->left==NULL &&  root->right==NULL){
            arr.push_back(root->val);
            currSum+=root->val;
            if(target==currSum)
                ans.push_back(arr);
            arr.pop_back();
            return;
        }
        arr.push_back(root->val);
        currSum+=root->val;
        
                
        Solve(root->left,target,currSum,ans,arr);

        Solve(root->right,target,currSum,ans,arr);
        arr.pop_back();
        
                
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> arr;
        int CurrSum=0;
        Solve(root,targetSum,CurrSum,ans,arr);
        return ans;
    }
};