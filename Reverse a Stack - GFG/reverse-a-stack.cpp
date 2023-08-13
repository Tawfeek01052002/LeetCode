//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void solve(stack<int> &s, int &sizeOfStack, int &data)
    {
        // base case
        if (s.size() == 0)
        {
            s.push(data);
            return;
        }
    
        int temp = s.top();
        s.pop();
    
        // recursive call
        solve(s, sizeOfStack, data);
    
        // backtrack
        s.push(temp);
    }
    void ReverseStack(stack<int> &s, int i, int &sizeOfStack)
    {
        if (i == sizeOfStack)
        {
            return;
        }
        int data = s.top();
        s.pop();
        ReverseStack(s, i + 1, sizeOfStack);
        solve(s, sizeOfStack, data);
    }
    void Reverse(stack<int> &St){
        int i=0;
        int sizeOfStack=St.size();
        ReverseStack(St,i,sizeOfStack);
        
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends