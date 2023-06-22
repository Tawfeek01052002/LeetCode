class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int start=0;
        int end=nums.size()-1;
        int curr=0;
        while(curr<=end){
            if(nums[curr]==0)
                curr++;
            else
                swap(nums[curr++],nums[start++]);
        }
        while(start<end)
            nums[start++]=0;
    }
};