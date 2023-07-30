class Solution {
public:
    //using include and exclude pattern of recursion
    //here we include '(' or include ')'
    void getValidParanthesis(int n,vector<string>& ans,string& str,int open,int close){
        if((open==0 && close==0)){
            ans.push_back(str);
            return;
        }
        
        if(open>0){
            str.push_back('(');
            getValidParanthesis(n,ans,str,open-1,close);
            
            //backtrack
            str.pop_back();
        }
        
        if(close>0 && open<close){
            str.push_back(')');
            getValidParanthesis(n,ans,str,open,close-1);
            
            //backtrack
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str;
        int open=n;
        int close=n;
        getValidParanthesis(n,ans,str,open,close);
        return ans;
    }
};