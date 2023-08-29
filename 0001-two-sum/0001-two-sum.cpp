class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //Brute Force
        for(int i=0;i<nums.size();i++){
            int ele=target-nums[i];
            for(int j=i+1;j<nums.size();j++){
                if(ele==nums[j]){
                    return {i,j};
                }
            }
        }
        return {0};
        
        
        //Find best solution == ?
        
        
        //Map solution is also exist
    }
};