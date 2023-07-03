class Solution {
public:
    string checkPalindrome(string s,int i,int j,string ans){
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