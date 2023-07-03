class Solution {
public:
    string checkPalindrome(string s,int i,int j,string ans){
        //     bool isPalindrome(string &str,int i,int j){
        //         while(i<j){
        //             if(str[i]!=str[j]){
        //                 return false;
        //             }
        //             i++;
        //             j--;
        //         }
        //         return true;
        //     }
        
        //Brute Force Approach 
        // T.C.=O(N^3)  S.C.=O(1)
        // string ans="";
        // int n=s.length();
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         if(isPalindrome(s,i,j)){
        //             string t=s.substr(i,j-i+1);
        //             ans=t.size()>ans.size()?t:ans;
        //         }
        //     }
        // }
        // return ans;
        
        // T.C.=O(N^2) S.C.=O(1)
        //Good Method
        int max=ans.length();
        while(i>=0 && j<s.length() && s[i]==s[j]){
            if(j-i>=max)
                ans=s.substr(i,j-i+1);
            i--;
            j++;
        }
        return ans;
    }
    
    string longestPalindrome(string s) {
        string ans="";
        for(int i=0;i<s.length();i++){
            ans=checkPalindrome(s,i,i,ans);
            ans=checkPalindrome(s,i,i+1,ans);   
        }
        return ans;
    }
};