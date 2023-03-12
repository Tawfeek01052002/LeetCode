class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        string ans=str[0];
        int n=str.size();
        int j=0;
        for(int i=1;i<n;i++){
            int len=ans.length();
            for(j=0;j<len && j<str[i].length();j++){
                string ch=str[i];
                if(ans[j]!=ch[j]){
                    break;
                }
            }
            ans=ans.substr(0,j);
        }
        return ans;
    }
};