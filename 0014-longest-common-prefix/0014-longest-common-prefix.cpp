class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        // T.C=O(N^2)
        //brute force approach not allowed
        // string ans=str[0];
        // int n=str.size();
        // int j=0;
        // for(int i=1;i<n;i++){
        //     int len=ans.length();
        //     for(j=0;j<len && j<str[i].length();j++){
        //         string ch=str[i];
        //         if(ans[j]!=ch[j]){
        //             break;
        //         }
        //     }
        //     ans=ans.substr(0,j);
        // }
        // return ans;
        
        
        string ans;
        int n=strs.size();
        int i=0;
        while(true){
            char curr=0;
            for(auto str:strs){
                if(i>=str.length()){
                    curr=0;
                    break;
                }
                if(curr==0){
                    curr=str[i];
                }
                if(curr!=str[i]){
                    curr=0;
                    break;
                }
            }
            if(curr==0){
                break;
            }
            ans.push_back(curr);
            i++;
        }
        return ans;
        
        // string ans;
        // int i=0;
        // while(true){
        //     char curr=0;
        //     for(auto str:strs){
        //         if(i>=str.size()){
        //             curr=0;
        //             break;
        //         }
        //         if(curr==0){
        //             curr=str[i];
        //         }
        //         if(curr!=str[i]){
        //             curr=0;
        //             break;
        //         }
        //     }
        //     if(curr==0){
        //         break;
        //     }
        //     ans.push_back(curr);
        //     i++;
        // }
        // return ans;
        
    }
};