class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp(nums.size(),0);
        for(int i=0;i<n;i++){
            temp[nums[i]-1]++;
        }
        for(int i=0;i<=n;i++){
            if(temp[i]>1)
                return i+1;
        }
        return 0;
        
    }
};