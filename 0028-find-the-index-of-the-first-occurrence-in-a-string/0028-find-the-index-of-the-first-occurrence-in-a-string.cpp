class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.length();
        int m=needle.length();
        bool b=false;
        for(int i=0;i<=n-m;i++){
            b=false;
            for(int j=0;j<m;j++){
                if(needle[j]!=haystack[i+j]){
                    b=true;
                    break;
                }
            }
            if(!b){
                return i;
            }
        }
        return -1;
    }
};