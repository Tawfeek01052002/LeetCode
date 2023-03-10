class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(ans.length()>0 && s[i]==ans[ans.length()-1]){
                ans.pop_back();
            }
            else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};