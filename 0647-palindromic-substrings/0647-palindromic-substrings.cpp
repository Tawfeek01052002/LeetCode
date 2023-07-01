class Solution {
public:
    
    //substrings of odd and even length
    int numberOfOddPalindrome(string s,int i){
        int j=i;
        int n=s.length();
        int count=0;
        while(i>=0 && j<n && s[i]==s[j]){
            count++;
            j++;
            i--;
        }
        return count;
    }
    
    int numberOfEvenPalindrome(string s,int i){
        int j=i+1;
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
            count=count+numberOfEvenPalindrome(s,i)+numberOfOddPalindrome(s,i);
        }
        return count;
    }
};