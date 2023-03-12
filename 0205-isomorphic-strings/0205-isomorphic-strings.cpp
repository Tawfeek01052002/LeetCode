class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.length();
        int m=t.length();
        if(n!=m){
            return false;
        }
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(s[i]==s[j] && t[i]!=t[j] || t[i]==t[j] && s[i]!=s[j]){
                        return false;
                    }
                
            }
        }
        return true;
    }
};