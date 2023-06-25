class Solution {
public:
    int mySqrt(int x) {
        
        //using inbuilt function
        // return sqrt(x);
        
        //using binary search
        int start=1,mid;
        int end=x;
        int num=0;
        while(start<=end){
            mid=start+(end-start)/2;
            if(mid==x/mid){
                return mid;
            }
            else if(mid<x/mid){
                num=mid;
                start=mid+1;
            }
            else
                end=mid-1;
        }
        return num;
    }
};