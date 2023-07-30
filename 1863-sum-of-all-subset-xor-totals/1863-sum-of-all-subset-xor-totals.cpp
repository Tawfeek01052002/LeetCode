class Solution {
public:
    
    void getSumOfXor(vector<int>& nums,int i,int& ans,int curr){
        if(i>=nums.size()){
            ans=ans+curr;
            return;
        }
        
        //include
        getSumOfXor(nums,i+1,ans,curr^nums[i]);
        
        //exclude
        getSumOfXor(nums,i+1,ans,curr);
    }
    
    int subsetXORSum(vector<int>& nums) {
        int ans=0;
        getSumOfXor(nums,0,ans,0);
        return ans;
    }
};