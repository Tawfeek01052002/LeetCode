class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
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
};

// 0 2 10 5 4 3 1