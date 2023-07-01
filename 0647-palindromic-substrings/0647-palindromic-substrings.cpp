class Solution {
public:
    
    //substrings of odd and even length
    int numberOfPalindrome(string s,int i,int j){
        int n=s.length();
        int count=0;
        while(i>=0 && j<n && s[i]==s[j]){
            count++;
            j++;
            i--;
        }
        return count;
    }
    int countSubstrings(string s) {
        int n=s.length();
        int count=0;
        for(int i=0;i<n;i++){
            count=count+numberOfPalindrome(s,i,i)+numberOfPalindrome(s,i,i+1);
        }
        return count;
    }
};