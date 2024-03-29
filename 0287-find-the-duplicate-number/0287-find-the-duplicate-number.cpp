class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        //Brute Force ---O(n*n);
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
        
        // Using Cyclic Sort -- O(n) time --- O(1) space--Modifying the  array 
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
        
        //OR --Cyclic sort
        // while(nums[0]!=nums[nums[0]]){
        //     swap(nums[0],nums[nums[0]]);
        // }
        // return nums[0];
        
        
        // Using bool temp array -- O(n) time -- O(n) space
        // vector<bool> temp(n,true);
        // for(int i=0;i<n;i++){
        //     int index=nums[i]-1;
        //     if(temp[index]){
        //         temp[index]=false;
        //     }
        //     else{
        //         return nums[i];
        //     }
        // }
        // return -1;
        
        
        //multiply element by -1 to check visited or not and then again multiply by -1 to remove modification
        
        //Modifying Array
        // int dupli=0;
        // for(int i=0;i<n;i++){
        //     int index=abs(nums[i])-1;
        //     if(nums[index]<0){
        //         dupli=abs(nums[i]);
        //         break;
        //     }
        //     else{
        //         nums[index]*=-1;
        //     }
        // }
        // //remove modification
        // for(int i=0;i<n;i++){
        //     nums[i]=abs(nums[i]);
        // }
        // return dupli;
        
        
        //Revise
        //Using temp array to store count
        // int n=nums.size();
        // vector<int> temp(nums.size(),0);
        // for(int i=0;i<n;i++){
        //     temp[nums[i]-1]++;
        //     if(temp[nums[i]-1]>1)
        //         return nums[i];
        // }
        // return 0;
        
//         int i=0;
//         int n=nums.size();
//         while(i<n)
//         {
//             int index=abs(nums[i]);
//             if(nums[index]<0)
//                 return index;
//             else
//                 nums[index]*=-1;
            
//             i++;
//         }
//         return 0;
        
        int i=0;
        while(nums[nums[i]]!=nums[i]){
            swap(nums[nums[i]],nums[i]);
        }
        return nums[0];
        
        
        
        
        
    }
};