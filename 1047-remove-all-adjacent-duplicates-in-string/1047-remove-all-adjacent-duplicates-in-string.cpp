class Solution {
public:
    string removeDuplicates(string s) {
        
        
        // T.C.=O(n)  S.C.=O(n)
        // int n=s.length();
        // string ans="";
        // for(int i=0;i<n;i++){
        //     if(ans.size()>0 && ans[ans.size()-1]==s[i])
        //         ans.pop_back();
        //     else
        //         ans.push_back(s[i]);
        // }
        // return ans;
        
        // T.C.=O(n)  S.C.=O(1)
        int i=0;
        int j=1;
        while(j<s.length()){
            if(i>=0 && s[i]==s[j]){
                i--;
                j++;
            }
            else{
                s[++i]=s[j++];
            }
        }
        return s.substr(0,i+1);
        
    }
};