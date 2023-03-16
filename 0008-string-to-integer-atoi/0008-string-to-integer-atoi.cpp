class Solution {
public:
    int myAtoi(string s) {
        // 1.Ignore leading whitespaces
        // 2.determine sign
        // 3.if digit found after finding sign
        // 4.fill till next non-digit char is found
        // 5.out of range handling
        
        int i=0,sign=1,num=0;
        while(s[i]==' '){
            i++;
        }
        bool b=false;
        while(i<s.size() && (s[i]=='-' || s[i]=='+')){
            if(b){
                return 0;
            }
            sign= s[i]=='+'?1:-1;
            i++;
            b=true;
            
        }
        
        while(i<s.size() && isdigit(s[i])){
            if(num> INT_MAX/10 || (num== INT_MAX/10 && s[i]>'7'))
                return sign==-1?INT_MIN:INT_MAX;
            num=num*10+(s[i]-'0');
            i++;
        }
        return num*sign;
    }
};