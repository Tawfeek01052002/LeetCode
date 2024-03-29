//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends



//Intutuion = cancel valid paranthesis using stack 
// if }{ == count+2
// if {{ || }}  == count+1

int countRev (string str)
{
    int n=str.length();
    if(n&1==1){
        return -1;
    }
    
    stack<char> s;

    for(int i=0;i<n;i++){
        char ch=str[i];
        if(ch=='{'){
            s.push(ch);
        }
        else if(ch=='}' && !s.empty() && s.top()=='{'){
            s.pop();
        }
        else{
            s.push(ch);
        }
    }
    
    int count=0;
    while(!s.empty()){
        char ch1=s.top();
        s.pop();
        char ch2=s.top();
        s.pop();
        
        if(ch1==ch2){
            count+=1;
        }
        else{
            count+=2;
        }
    }
    return count;
}