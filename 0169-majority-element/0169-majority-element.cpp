class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        //Brute Force Approach
        // int count=0;
        // for(int i=0;i<nums.size();i++){
        //     count=0;
        //     if(nums[i]!=INT_MIN){
        //         for(int j=i+1;j<nums.size();j++){
        //             if(nums[i]==nums[j]){
        //                 nums[j]=INT_MIN;
        //                 count++;
        //             }
        //         }
        //     }
        //     if(count>=nums.size()/2){
        //         return nums[i];
        //     }
        // }
        // return 0;
        
        //Using Sorting
        int n=nums.size();
        if(n==1 || n==2){
            return nums[0];
        }
        int count=1;
        sort(nums.begin(), nums.end());
        for(int i=0,j=1;i<n&&j<n;){
            if(nums[i]==nums[j]){
                count++;
                j++;
            }
            else {
                i=j;
                count=1;
                j++;
                
            }
            if(count>n/2){
                return nums[i];
            }
        }
        return 0;
    }
};