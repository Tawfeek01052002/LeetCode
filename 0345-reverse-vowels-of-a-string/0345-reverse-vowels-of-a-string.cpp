class Solution {
public:
    // T.C.=O(N)  S.C.=O(1)
    bool isVowel(char ch){
        ch=(char)tolower(ch);
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
            return true;
        else
            return false;
    }
    string reverseVowels(string str) {
        int s=0;
        int e=str.length()-1;
        while(s<e){
            if(!isVowel(str[s])){
                s++;
            }
            else if(!isVowel(str[e])){
                e--;
            }
            else{
                swap(str[s],str[e]);
                s++;
                e--;
            }
        }
        return str;
    }
};