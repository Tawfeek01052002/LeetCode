//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // Using Dutch National Flag Algorithm -- O(n)
        // int s,m,e;
        // s=m=0;
        // e=n-1;
        // while(m<=e){
        //     if(a[m]==1){
        //         m++;
        //     }
        //     else if(a[m]==0){
        //         swap(a[m],a[s]);
        //         m++;
        //         s++;
        //     }
        //     else if(a[m]==2){
        //         swap(a[m],a[e]);
        //         e--;
        //     }
        // }
        
        //Using Counting the number of Occurence of all three numbers
        int z,o,t;
        z=o=t=0;
        for(int i=0;i<n;i++){
            if(a[i]==0)
                z++;
            else if(a[i]==1)
                o++;
            else
                t++;
        }
        int i=0;
        while(z-->0){
            a[i]=0;
            i++;
        }
        while(o-->0){
            a[i]=1;
            i++;
        }
        while(t-->0){
            a[i]=2;
            i++;
        }
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends