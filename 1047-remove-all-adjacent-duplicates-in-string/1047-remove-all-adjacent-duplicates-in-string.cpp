class Solution {
public:
    string removeDuplicates(string str) {
        stack<char> s;
        
        for(int i=str.length()-1;i>=0;i--){
            char ch=str[i];
            if(s.empty() || s.top()!=ch){
                s.push(ch);
            }
            else{
                s.pop();
            }
        }
        string out;
        while(!s.empty()){
            out.push_back(s.top());
            s.pop();
        }
        return out;
    }
};