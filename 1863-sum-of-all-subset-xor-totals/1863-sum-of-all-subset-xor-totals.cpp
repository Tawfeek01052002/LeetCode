class Solution {
public:
    int getXor(vector<int>& nums,int i,int xorr){
        if(i>=nums.size())
            return xorr;
        
        //include
        return getXor(nums,i+1,xorr^nums[i])+getXor(nums,i+1,xorr);
    }
    int subsetXORSum(vector<int>& nums) {
        int i=0;
        int xorr=0;
        return getXor(nums,i,xorr);
    }
};