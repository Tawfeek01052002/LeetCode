class Solution {
public:
    //using recursion with stack
    void removePara(string& str,stack<char>& s,int& i,string& ans){
        if(i>=str.length()){
            return;
        }
        if(str[i]=='('){
            if(!s.empty()){
                ans.push_back('(');
            }
            s.push(str[i]);
        }
        else{
            s.pop();
            if(!s.empty()){
                ans.push_back(')');
            }
        }
        i++;
        removePara(str,s,i,ans);
    }
    string removeOuterParentheses(string str) {
        int i=0;
        stack<char> s;
        string ans;
        removePara(str,s,i,ans);
        return ans;
    }
};