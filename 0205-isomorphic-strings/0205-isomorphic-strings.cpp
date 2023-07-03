class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char arr[256]={0};
        bool ismapped[256]={false};
        for(int i=0;i<s.length();i++){
            if(arr[s[i]]==0 && ismapped[t[i]]==0){
                arr[s[i]]=t[i];
                ismapped[t[i]]=true;
            }
            if(arr[s[i]]!=t[i])
                return false;
        }
        return true;
    }
};