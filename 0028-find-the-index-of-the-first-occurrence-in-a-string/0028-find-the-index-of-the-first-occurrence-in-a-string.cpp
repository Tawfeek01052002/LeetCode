class Solution {
public:
    int strStr(string haystack, string needle) {
        
        //using inbuild find function
        // int index=haystack.find(needle);
        // if(index!=string::npos)
        //     return index;
        // return -1;
        
        //checking substrings
        // also called we are using sliding window
        // int n=haystack.length();
        // int m=needle.length();
        // for(int i=0;i<=n-m;i++){
        //     if(haystack[i]==needle[0] && haystack.substr(i,m).compare(needle)==0)
        //         return i;
        // }
        // return -1;
        
        
        //without using substr
        int n=haystack.length();
        int m=needle.length();
        for(int i=0,j;i<=n-m;i++){
            for(j=0;j<m;j++){
                if(needle[j]!=haystack[i+j]){
                    break;
                }
            }
            if(j==m){
                return i;
            }
        }
        return -1;
        
    }
};