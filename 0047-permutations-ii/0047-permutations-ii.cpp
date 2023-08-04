class Solution {
public:
    void allPerm(vector<int>& nums,int i,set<vector<int>>& ans){
        if(i>=nums.size()){
            ans.insert(nums);
            return;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            allPerm(nums,i+1,ans);
            swap(nums[i],nums[j]);
        }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        vector<vector<int>> out;
        allPerm(nums,0,ans);
        for (const vector<int>& v : ans) {
            out.push_back(v);
        }
        return out;
    }
};