class Solution {
public:
    
    //First we Found Pivot the apply binary search on left of pivot (0,pivot-1)
    // if index ==-1 then search in right array (pivot,arr.size()-1)
    // else return -1
    int binarySearch(vector<int> arr,int target,int s,int e){
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
    
    int findpivot(vector<int>nums){
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
        return s;
    }
    
    int search(vector<int>& arr, int target) {
        int pivot=findpivot(arr);
        cout<<"Pivot = "<<pivot;
        if(arr[pivot]<=target && target<=arr[arr.size()-1]){
            //Search in right array
            return binarySearch(arr,target,pivot,arr.size()-1);
        }
        else{
            //Search in left array
            return binarySearch(arr,target,0,pivot-1);
        }
        return -1;
    }
};