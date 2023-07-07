//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> getPrime(int n){
        vector<int> arr;
        vector<bool> prime(n+1,true);
        prime[0]=prime[1]=false;
        for(int i=2;i*i<n;i++){
            if(prime[i]){
                int j=i*i;
                while(j<n){
                    prime[j]=false;
                    j+=i;
                }
            }
        }
        for(int i=2;i<=n;i++)
            if(prime[i])
                arr.push_back(i);
        return arr;
    }
    
    //using segmented sieve
    long long primeProduct(long long L, long long R){
        // code here
        
        vector<bool> arr(R-L+1,true);
        vector<int> primes=getPrime(sqrt(R));
        // for(auto ele:primes){
        //     cout<<ele<<endl;
        // }
        for(long long int ele:primes){
            
            long long ff=(L/ele)*ele;
            if(ff<L)
                ff+=ele;
                
            // cout<<firstFactor<<endl;
            
            for(long long int j=max(ff,ele*ele);j<=R;j+=ele){
                arr[j-L]=false;
            }
        }
        long long product=1;
        long mod = 1e9+7;
        for(int i=L;i<=R;i++)
        {
            if(arr[i-L])
            {
                product = product*i;
                product = product%mod;
            }
        }
        return product;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long L, R;
        cin>>L>>R;
        
        Solution ob;
        cout<<ob.primeProduct(L, R)<<"\n";
    }
    return 0;
}
// } Driver Code Ends