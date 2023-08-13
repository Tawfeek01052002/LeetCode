//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string s)
    {
        // Your code here
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

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends