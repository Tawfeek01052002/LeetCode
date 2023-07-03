class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int n=haystack.length();
        int m=needle.length();
        for(int i=0;i<=n-m;i++){
            if(haystack[i]==needle[0] && haystack.substr(i,m).compare(needle)==0)
                return i;
        }
        return -1;
    }
};