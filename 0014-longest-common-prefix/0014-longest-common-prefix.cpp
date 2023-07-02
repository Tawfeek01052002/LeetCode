class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        string ans=str[0];
        int n=str.size();
        for(int i=1;i<n;i++){
            int index=0;
            while(index<ans.length() &&index<str[i].length() && ans[index]==str[i][index]){
                index++;
            }
            ans=ans.substr(0,index);
        }
        return ans;
    }
};