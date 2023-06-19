class Solution {
public:
    int reverse(int x) {
        
        int isPos=1;
        if(x<0){
            isPos=-1;
        }
            
        int reverse=0;
        while(x!=0){
            if(INT_MAX/10 < reverse || INT_MIN/10>reverse){
                return 0;
            }
            int rem=x%10;
            reverse=reverse*10+rem;
            x/=10;
        }
        return reverse;
    }
};