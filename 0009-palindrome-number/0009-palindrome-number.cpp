class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int tempx=x;
        int mod=INT_MAX;
        int revNum=0;
        while(tempx>0){
            int digit=tempx%10;
            tempx=tempx/10;
            if(revNum > mod/10) return false;
            revNum=(revNum*10) + digit;
        }
        return revNum == x;
    }
};