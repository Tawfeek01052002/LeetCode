class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> temp(nums.size(),0);
        for(int i=0;i<n;i++){
            temp[nums[i]-1]++;
            if(temp[nums[i]-1]>1)
                return nums[i];
        }
        return 0;
        
        
        
    }
};