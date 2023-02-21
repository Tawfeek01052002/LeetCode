class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=findFirst(nums,target);
        int last=findLast(nums,target);
        return {first,last};
    }
    
    int findFirst(vector<int> &nums,int target){
        int index=-1;
        int s=0;
        int e=nums.size()-1;
        int mid=s+(e-s)/2;
        while(s<=e){
            if(nums[mid]==target){
                index=mid;
                e=mid-1;
            }
            else if(nums[mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return index;
    }
    
    int findLast(vector<int> &nums,int target){
        int index=-1;
        int s=0;
        int e=nums.size()-1;
        int mid=s+(e-s)/2;
        while(s<=e){
            if(nums[mid]==target){
                index=mid;
                s=mid+1;
            }
            else if(nums[mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return index;
    }
};