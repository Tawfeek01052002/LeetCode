class Solution {
public:
    void allPerm(vector<int>& nums,int i,vector<vector<int>>& ans){
        if(i>=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            allPerm(nums,i+1,ans);
            swap(nums[i],nums[j]);
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        allPerm(nums,0,ans);
        return ans;
    }
};