class Solution {
public:
    //
    string longest(string str,int i,int j,int n){
        string ans="";
        while(i>=0 && j<n){
            if(str[i]==str[j]){
                ans=str.substr(i,j-i+1);
                i--;
                j++;
            }
            else{
                return ans;
            }
        }
        return ans;
    }
    string longestPalindrome(string s) {
        string max;
        long maxi=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            string odd=longest(s,i,i,n);
            if(odd.length()>maxi){
                max=odd;
                maxi=max.length();
            }
            string even=longest(s,i,i+1,n);
            if(even.length()>maxi){
                max=even;
                maxi=max.length();
            }
        }
        return max;
    }
};