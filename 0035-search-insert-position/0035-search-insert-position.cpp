class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        // int start=0;
        // int end=arr.size()-1;
        // int index=end+1;
        // while(start<=end){
        //     int mid=start+(end-start)/2;
        //     if(arr[mid]==target)
        //         return mid;
        //     else if(arr[mid]>target){
        //         index=mid;
        //         end=mid-1;
        //     }
        //     else
        //         start=mid+1;
        // }
        // return index;
        int left = 0;
    int right = arr.size() - 1;
    int ceil = arr.size();

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
        {
            ceil = mid;
            right = mid - 1;
        }
    }

    return ceil;
    }
};