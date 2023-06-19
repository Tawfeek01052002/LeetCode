class Solution {
public:
    int reverse(int x) {
        int reverse=0;
        while(x!=0){
            if(INT_MAX/10 < reverse || INT_MIN/10>reverse){
                return 0;
            }
            int rem=x%10;
            // cout<<"rem = "<<rem<<endl;
            reverse=reverse*10+rem;
            // cout<<"reverse = "<<reverse<<endl;
            x/=10;
        }
        return reverse;
    }
};