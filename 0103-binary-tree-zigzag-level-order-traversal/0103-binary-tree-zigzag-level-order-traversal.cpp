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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL) 
            return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        bool flag=true;
        while(!q.empty()){
            int lvl=q.size();
            vector<int> inner(lvl);
            int index=0;
            while(lvl-->0){
                TreeNode* temp=q.front(); q.pop();
                
                if(flag==true)
                    inner[index++]=temp->val;
                else
                    inner[lvl]=temp->val;
                
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }
            }
            flag=!flag;
            ans.push_back(inner);
        }
        return ans;
    }
};