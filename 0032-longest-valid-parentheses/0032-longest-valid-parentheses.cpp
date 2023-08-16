class Solution {
public:
    ///solve using stack - pushing index of string in stack and getting size 
    int longestValidParentheses(string str) {
        
        //stack
        stack<int> s;
        s.push(-1);
        int maxi=0;
        for(int i=0;i<str.length();i++){
            char ch=str[i];
            if(ch=='('){
                s.push(i);
            }
            else{
                s.pop();
                if(!s.empty()){
                    int len=i-s.top();
                    maxi=max(maxi,len);
                }
                else{
                    s.push(i);
                }
            }
        }
        return maxi;
    }
};