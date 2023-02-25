class Solution {
public:
    int divide(int dividend, int divisor) {
        
        //Handling edge test cases that is INT_MIN and INT_MAX with 1 and -1
        long temp=dividend;
        if(abs(temp)>INT_MAX && abs(divisor)==1){
            if ((dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0))
                return INT_MAX;
            else
                return dividend;
        }
        
        //General Test Cases including -ve 
        long s = 0;
        long e = abs(dividend);
        long mid = s + (e - s) / 2;
        long ans = 0;
        while (s <= e)
        {
            // Perfect Solution
            if (abs(mid * divisor) == abs(dividend))
            {
                ans = mid;
                break;
            }
            else if (abs(mid * divisor) < abs(dividend))
            {
                // right search
                ans = mid;
                s = mid + 1;
            }
            else
                e = mid - 1; // Left search
            mid = s + (e - s) / 2;
        }
        if ((dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0))
            return (int)ans;
        else
            return (int)-ans;
        }
};