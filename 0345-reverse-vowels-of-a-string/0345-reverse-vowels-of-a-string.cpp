class Solution {
public:
    // T.C.=O(N)  S.C.=O(1)
    bool isVowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' ||
          ch=='E' || ch=='I' || ch=='O' || ch=='U') 
            return true;
        else
            return false;
    }
    
    //Using 2 pointer approach s=0  and e=n-1
    string reverseVowels(string str) {
        int s=0;
        int e=str.length()-1;
        while(s<e){
            if(!isVowel(str[s]))
                s++;
            else if(!isVowel(str[e]))
                e--;
            else{
                swap(str[s],str[e]);
                s++;
                e--;
            }
        }
        return str;
    }
};