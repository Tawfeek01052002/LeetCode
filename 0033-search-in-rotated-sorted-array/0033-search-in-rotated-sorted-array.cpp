class Solution {
public:
    int binary(vector<int> arr,int target,int s,int e){
        int mid=s+(e-s)/2;
        while(s<=e){
            if(arr[mid]==target)
                return mid;
            else if(arr[mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        int mid=s+(e-s)/2;
        while(s<e){
            if(nums[mid]>=nums[0])
                s=mid+1;
            else
                e=mid;
            mid=s+(e-s)/2;
        }
        int pivot=s;
        // cout<<"Pivot = "<<pivot;
        int index=binary(nums,target,0,pivot-1);
        if(index!=-1)
            return index;
        else{
            index=binary(nums,target,pivot,nums.size()-1);
            if(index!=-1){
                return index;
            }
            else{
                return -1;
            }
        }
        return -1;
    }
};