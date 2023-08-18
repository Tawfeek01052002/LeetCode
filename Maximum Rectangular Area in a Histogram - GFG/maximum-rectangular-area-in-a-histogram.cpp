//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    vector<long long> moveLeft(long long arr[],int n){
        vector<long long> left(n,-1);
        stack<long long> s;
        s.push(-1);
        for(int i=0;i<n;i++){
            while(s.size()>1 && arr[i]<=arr[s.top()]){
                s.pop();
            }
            left[i]=s.top();
            s.push(i);
        }
        return left;
    }
    
    vector<long long> moveRight(long long arr[],int n){
        vector<long long> right(n,-1);
        stack<long long> s;
        s.push(-1);
        for(int i=n-1;i>=0;i--){
            while(s.size()>1 && arr[i]<=arr[s.top()]){
                s.pop();
            }
            right[i]=s.top();
            s.push(i);
        }
        return right;
    }
    long long getMaxArea(long long arr[], int n)
    {
        vector<long long> left=moveLeft(arr,n);
        vector<long long> right=moveRight(arr,n);
        long long maxArea=0;
        for(int i=0;i<n;i++){
            long long length=arr[i];
            if(right[i]==-1){
                right[i]=n;
            }
            long long breadth=right[i]-left[i]-1;
            long long area=length*breadth;
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends