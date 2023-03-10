class Solution {
public:
    bool isPalindrome(string str){
        int s=0;
        int e=str.length()-1;
        while(s<e){
            if(str[s]!=str[e]){
                return false;
            }
            s++;
            e--;
        }
        return true;
    }
    
    // checking left substring and rightsubstring is palindrome or not 
    // when characters is not match
    bool validPalindrome(string s) {
        int start=0;
        int end=s.length()-1;
        while(start<end){
            if(s[start]!=s[end]){
                return isPalindrome(s.substr(start,end-start))||isPalindrome(s.substr(start+1,end-start));
            }
            start++;
            end--;
        }
        return true;
    }
};