class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        int e=n-1;
        
        if(n<=1 || nums[s]<nums[e]){
            return nums[0];
        }
        
        int mid=s+(e-s)/2;
        while(s<e){
            if(nums[mid]>=nums[0])
                s=mid+1;
            else 
                e=mid;
            mid=s+(e-s)/2;
        }
        return nums[s];
        
    }
};