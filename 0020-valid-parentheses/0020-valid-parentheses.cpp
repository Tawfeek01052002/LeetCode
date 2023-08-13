class Solution {
public:
    bool isValid(string s) {
        stack<char> open;
        
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            
            //opening bracket
            if(ch=='(' || ch=='{' || ch=='['){
                open.push(ch);
            }
            else if(!open.empty()){
                char topCh=open.top();
                if((ch==')' && topCh == '(') ||(ch=='}' && topCh == '{') ||(ch==']' && topCh == '[')){
                    open.pop();
                }
                else{
                    return false;
                }
            }
            else{
                  return false;
            }
            
        }
        
        if(open.empty()){
            return true;
        }
        return false;
    }
};