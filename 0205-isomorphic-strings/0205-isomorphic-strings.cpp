class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.length();
        char hash[256]={0};
        bool isMapped[256]={0};
        for(int i=0;i<n;i++){
            if(hash[s[i]]==0 && isMapped[t[i]]==0){
                hash[s[i]]=t[i];
                isMapped[t[i]]=true;
            }
            if(hash[s[i]]!=t[i]){
                return false;
            }
        }
        return true;
        
    }
};