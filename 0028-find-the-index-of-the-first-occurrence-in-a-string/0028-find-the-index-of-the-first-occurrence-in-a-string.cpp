class Solution {
public:
    int strStr(string haystack, string needle) {
        // return haystack.find(needle);
        int n=haystack.length();
        int m=needle.length();
        int index=-1;
        int i=0,temp=i,j=0;
        for(;i<=n-m && temp<n && j<m;){
            if(haystack[temp]!=needle[j]){
                i++;
                temp=i;
                j=0;
            }
            else{
                temp++;
                j++;
            }
            if(j==m){
                index=i;
                break;
            }
        }
        return index;
    }
};