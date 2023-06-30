class Solution {
public:
    string removeDuplicates(string s) {
        
        int n=s.length();
        string ans="";
        for(int i=0;i<n;i++){
            if(ans.size()==0)
                ans.push_back(s[i]);
            else if(ans[ans.size()-1]==s[i])
                ans.pop_back();
            else
                ans.push_back(s[i]);
        }
        return ans;
        
    }
};