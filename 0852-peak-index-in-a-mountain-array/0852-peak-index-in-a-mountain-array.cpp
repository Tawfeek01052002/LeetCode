class Solution {
public:
    int findPeakIndex(vector<int> &arr){
         int s=0;
        int e=arr.size()-1;
        int m=s+(e-s)/2;
        while(s<e){
            if(arr[m]>arr[m+1])
                e=m;
            else
                s=m+1;
            m=s+(e-s)/2;
        }
        return s;
    }
    int peakIndexInMountainArray(vector<int>& arr) {
        return findPeakIndex(arr);
    }
};