class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int miss=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
            miss=miss^nums[i]^(i+1);
        return miss;
    }
    
};