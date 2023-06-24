class Solution {
public:
    int binarySearch(vector<int> arr,int start,int end,int target){
        int mid=0;
        while(start<=end){
            mid=start+(end-start)/2;
            if(arr[mid]==target)
                return mid;
            else if(arr[mid]>target)
                end=mid-1;
            else
                start=mid+1;
        }
        return -1;
    }
    int pivotElement(vector<int> arr){
        int start=0;
        int end=arr.size()-1;
        int mid=0;
        while(start<end){
            mid=start+(end-start)/2;
            if(mid<end && arr[mid]>arr[mid+1]){
                return mid;
            }
            else if(mid>start && arr[mid]<arr[mid-1]){
                return mid-1;
            }
            else if(arr[start]>arr[mid]){
                end=mid-1;
            }
            else{
                start=mid+1;
            }  
        }
        return arr.size()-1;
    }
    
    int search(vector<int>& arr, int target) {
        int pivot=pivotElement(arr);
        cout<<"Pivot = "<<pivot;
        if(arr[0]<=target){
            //Search in left array
            return binarySearch(arr,0,pivot,target);
        }
        else{
            //Search in Right array
            return binarySearch(arr,pivot+1,arr.size()-1,target);
        }
        return -1;
    }
};