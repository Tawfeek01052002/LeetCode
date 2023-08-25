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
    vector<vector<int>> levelOrder(TreeNode*& root) {
        if (root == NULL) 
            return {};
        vector<vector<int>> ans;
        queue<TreeNode*> que;
        que.push(root);
        int levelSize;
        while(!que.empty()){
            levelSize=que.size();
            vector<int> arr;
            for(int i=0;i<levelSize;i++){
                TreeNode* temp=que.front();
                que.pop();
                arr.push_back(temp->val);
                if(temp->left!=NULL)
                    que.push(temp->left);
                if(temp->right!=NULL)
                    que.push(temp->right);
            }
            ans.push_back(arr);
        }
        return ans;
    }
};