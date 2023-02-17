class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            count=0;
            if(nums[i]!=INT_MIN){
                for(int j=i+1;j<nums.size();j++){
                    if(nums[i]==nums[j]){
                        nums[j]=INT_MIN;
                        count++;
                    }
                }
            }
            if(count>=nums.size()/2){
                return nums[i];
            }
        }
        return 0;
    }
};