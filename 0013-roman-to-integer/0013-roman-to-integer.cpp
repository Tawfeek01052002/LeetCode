class Solution {
public:
    
    //We Can also use map but avoid use of map
    // T.C.=O(N) S.C.=O(1)
    int mapped(char ch){
        switch(ch){
            case 'M':return 1000;
            case 'D':return 500;
            case 'C':return 100;
            case 'L':return 50;
            case 'X':return 10;
            case 'V':return 5;
            case 'I':return 1;
        }
        return -1;
    }
    int romanToInt(string s) {
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(mapped(s[i])<mapped(s[i+1])){
                ans+=(mapped(s[i+1])-mapped(s[i]));
                i++;
            }
            else{
                ans+=(mapped(s[i]));
            }
        }
        return ans;
    }
};