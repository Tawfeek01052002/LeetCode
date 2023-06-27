class Solution {
public:
    
    //First Position
    int lowerBound(vector<int> arr, int x){
        int start=0;
        int end=arr.size()-1;
        int index=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid]==x){
                index=mid;
                end=mid-1;
            }
            else if(arr[mid]<x){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return index;
    }
    
    //Last Position
    int upperBound(vector<int> arr, int x){
        int start=0;
        int end=arr.size()-1;
        int index=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid]==x){
                index=mid;
                start=mid+1;
            }
            else if(arr[mid]<x){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return index;
    }
    
    
    vector<int> searchRange(vector<int>& nums, int target) {
        return {lowerBound(nums,target),upperBound(nums,target)};
    }
};