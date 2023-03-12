class Solution {
public:
    string reverseOnlyLetters(string str) {
        int s=0;
        int e=str.length()-1;
        while(s<e){
            if(str[s]>='A' && str[s]<='Z' || str[s]>='a' && str[s]<='z'){
                if(str[e]>='A' && str[e]<='Z' || str[e]>='a' && str[e]<='z')
                    swap(str[s++],str[e--]);
                else
                    e--;
            }
            else{
                s++;
            }
        }
        return str;
    }
};