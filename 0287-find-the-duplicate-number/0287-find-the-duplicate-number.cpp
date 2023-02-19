class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(nums[i]==nums[j]){
        //             return nums[i];
        //         }
        //     }
        // }
        // return -1;
            
        //Using Sorting
        // sort(nums.begin(),nums.end());
        // for(int i=0;i<n;i++){
        //     if(nums[i]==nums[i+1]){
        //         return nums[i];
        //     }
        // }
        // return -1;
        
        // Using Cyclic Sort
        // for(int i=0;i<n;){
        //     int index=nums[i];
        //     if(i==(index-1)){
        //         i++;
        //     }
        //     else if(nums[index-1]!=nums[i]){
        //         swap(nums[index-1],nums[i]);
        //     }
        //     else {
        //         return nums[i];
        //     }
        // }             
        // return -1;
        
        // Using bool temp array
        vector<bool> temp(n,true);
        for(int i=0;i<n;i++){
            int index=nums[i]-1;
            if(temp[index]){
                temp[index]=false;
            }
            else{
                return nums[i];
            }
        }
        return -1;

    }
};