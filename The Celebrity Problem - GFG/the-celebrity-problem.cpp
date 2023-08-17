//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
        for(int i=0;i<n;i++){
            s.push(i);
        }
        
        while(s.size()>1){
            int p1=s.top(); s.pop();
            int p2=s.top(); s.pop();
            if(M[p1][p2]){
                s.push(p2);
            }
            else{
                s.push(p1);
            }
        }
        
        int ans=s.top();
        s.pop();
        //checking that is the last person is celebrity or not
        for(int i=0;i<n;i++){
            if(M[ans][i]){
                return -1;
            }
        }
        for(int i=0;i<n;i++){
            if(M[i][ans]==0 && i!=ans){
                return -1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends