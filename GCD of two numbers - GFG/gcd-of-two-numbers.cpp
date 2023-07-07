//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
	public:
    int gcd(int A, int B) 
	{ 
	    // code here
	    while(1){
	        if(!A)
	            return B;
	        else if(!B)
	            return A;
	        if(A<=B)
	            B=B-A;
	        else
	            A=A-B;
	    }
	    return 0;
	      
	} 
};

//{ Driver Code Starts.

int main() 
{
   	int t;
    cin >> t;
    while (t--)
    {
        int A, B;
        cin >> A >> B;
        Solution ob;
       	cout <<  ob.gcd(A, B) << "\n";
    }
    return 0;
}
// } Driver Code Ends