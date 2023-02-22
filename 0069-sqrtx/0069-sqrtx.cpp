class Solution {
public:
    int mySqrt(int x) {
        
        //using inbuilt function
        // return sqrt(x);
        
        //using binary search
        int s=1;
        int e=x;
        int mid=s+(e-s)/2;
        while(s<=e){
            if(mid==x/mid){
                return mid;
            }
            else if(mid>x/mid){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return e;
        
    }
};