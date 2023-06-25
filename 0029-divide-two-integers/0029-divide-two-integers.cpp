class Solution {
public:
    int divide(int dividend, int divisor) {
        
        if(dividend == INT_MIN && abs(divisor)== 1)
            if(divisor<0)
                return INT_MAX;
            else
                return dividend;
            
        
        long start=0;
        long end=abs(dividend);
        long mid=0;
        long quo=0;
        while(start<=end){
            mid=start+(end-start)/2;         
            if(abs(mid*divisor)==abs(dividend)){
                quo=mid;
                break;
            }
            else if(abs(mid*divisor)<abs(dividend)){
                quo=mid;
                start=mid+1;
            }
            else
                end=mid-1;
        }
        if ((dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0))
            return (int)quo;
        else
            return (int)-quo;
        
    }
};