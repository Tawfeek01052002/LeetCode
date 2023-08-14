//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int checkRedundancy(string str) {
        // code here
        stack<char> s;
        for(int i=0;i<str.size();i++){
            char ch=str[i];
            if(ch=='(' || ch=='+' || ch=='-' || ch=='/' ||ch== '*'){
                s.push(ch);
            }
            else if(ch==')' && !s.empty()){
                bool isOperator=false;
                while(!s.empty() && s.top()!='('){
                    if(s.top()=='+' || s.top()=='-' || s.top()=='/' || s.top()=='*'){
                        isOperator=true;
                    }
                    s.pop();
                }
                if(s.empty()){
                    return true;
                }
                s.pop();
                if(!isOperator){
                    return true;
                }
            }
            else if(ch==')' && s.empty()){
                cout<<ch<<" ";
                return true;
            }
        }
        return false;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
    
        string s; 
        cin>>s;
        
        Solution obj;
        int res = obj.checkRedundancy(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends