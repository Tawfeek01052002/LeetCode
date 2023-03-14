class Solution {
public:
    // string longest(string str,int i,int j,int n){
    //     string ans="";
    //     while(i>=0 && j<n){
    //         if(str[i]==str[j]){
    //             ans=str.substr(i,j-i+1);
    //             tempi=i;
    //             tempj=j;
    //             i--;
    //             j++;
    //         }
    //         else{
    //             return ans;
    //         }
    //     }
    //     return ans;
    // }
    
    bool isPalindrome(string &str,int i,int j){
        while(i<j){
            if(str[i]!=str[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    string longestPalindrome(string s) {
        
        // T.C.=O(N^2) S.C.=O(1)
        //Method 1 :
        // string max;
        // int n=s.length();
        // for(int i=0;i<n;i++){
        //     string odd=longest(s,i,i,n);
        //     if(odd.length()>max.length()){
        //         max=odd;
        //     }
        //     string even=longest(s,i,i+1,n);
        //     if(even.length()>max.length()){
        //         max=even;
        //     }
        // }
        // return max;
        
        string ans="";
        int n=s.length();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(s,i,j)){
                    string t=s.substr(i,j-i+1);
                    ans=t.size()>ans.size()?t:ans;
                }
            }
        }
        return ans;
    }
};