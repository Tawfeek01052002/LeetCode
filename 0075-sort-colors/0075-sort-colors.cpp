class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        //Using Sort function
        // sort(nums.begin(),nums.end());
        
        //Using Counting
//         int zero=0,one=0,two=0;
        
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]==0)
//                 zero++;
//             else if(nums[i]==1)
//                 one++;
//             else
//                 two++;
//         }
//         int i=0;
//         while(zero-->0)
//             nums[i++]=0;
//         while(one-->0)
//             nums[i++]=1;
//         while(two-->0)
//             nums[i++]=2;
        
        //Dutch National Flag 
        //Using 3 Pointers
        int low=0,mid=0,high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0)
                swap(nums[mid++],nums[low++]);
            else if(nums[mid]==2)
                swap(nums[mid],nums[high--]);
            else
                mid++;
        }
        
    }
};