class Solution {
public:
    bool isVowel(char c){
        if(toupper(c)=='A' ||toupper(c)=='E'  ||toupper(c)=='I'  || toupper(c)=='O' || toupper(c)=='U'  )
            return true;
        return false;
    }
    string reverseVowels(string s) {
        int start=0;
        int end=s.length()-1;
        while(start<=end){
            if(!isVowel(s[start])){
                start++;
            }
            else if(!isVowel(s[end])){
                end--;
            }
            else
                swap(s[start++],s[end--]);
        }
        return s;
    }
};