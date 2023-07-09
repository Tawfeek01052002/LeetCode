class Solution {
public:
    bool isPowerOfTwo(int n) {
        // if(n>0 && (n==2 || n==1))
        //     return true;
        // if(n&1==1 || n==0)
        //     return false;
        // return isPowerOfTwo(n/2);
        
        if(n==0) return false;
        return (n==1) ||(!(n&1) && isPowerOfTwo(n>>1));
    }
};