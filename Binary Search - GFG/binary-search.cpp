//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
      int search(int arr[], int x, int start, int end)
    {
        if (start > end)
            return -1;
        int mid = start + (end - start) / 2;
        if (arr[mid] == x)
            return mid;
        return arr[mid] > x ? search(arr, x, start, mid - 1) : search(arr, x, mid + 1, end);
    }
    int binarysearch(int arr[], int n, int k) {
        // code here
        // int start=0;
        // int end=n-1;
        // int mid=0;
        // while(start<=end){
        //     mid=start+end-start/2;
        //     if(arr[mid]==k){
        //         return mid;
        //     }
        //     else if(arr[mid]>k){
        //         end=mid-1;
        //     }
        //     else{
        //         start=mid+1;
        //     }
        // }
        // return -1;
        
        //Using Exponential Search- Applying binary search on part of array in which the element may lie
        // if(arr[0]==k)
        //     return 0;
        // int i=1;
        // while(i<n && arr[i]<=k){
        //     i=i*2;
        // }
        // int start=i/2;
        // int end=min(n-1,i);
        // // cout<<"Start = "<<start<<endl;
        // // cout<<"End = "<<end<<endl;
        // //Now apply binary search to this part
        // while(start<=end){
        //     int mid=start+(end-start)/2;
        //     if(arr[mid]==k)
        //         return mid;
        //     else if(arr[mid]>k)
        //         end=mid-1;
        //     else 
        //         start=mid+1;
        // }
        // return -1;
        
        //using recursion
        int start=0;
        int end=n-1;
        return search(arr, k, start, end);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        int key;
        cin >> key;
        Solution ob;
        int found = ob.binarysearch(arr, N, key);
        cout << found << endl;
    }
}

// } Driver Code Ends