class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int ans=0;
        int sign=1;
        while(i<s.length() && s[i]==' '){
            i++;
        }
        
        if(i<s.length() && s[i]=='-' || s[i]=='+'){
            sign= s[i]=='-'?-1:1;
            i++;
        }
        
        while(i<s.length() && isdigit(s[i])){ 
            if(ans>INT_MAX/10 || (ans==INT_MAX/10 && s[i]>'7'))
                return sign==-1?INT_MIN:INT_MAX;
            ans=ans*10+(s[i]-'0');
            i++;
        }
        return ans*sign;
    }
};