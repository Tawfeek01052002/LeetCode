//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int k) {
         queue<long long int > que;
         
         //process first window of size k
         for(long long int i=0;i<k;i++){
             if(A[i]<0){
                 que.push(i);
             }
         }
         vector<long long> ans;
         
         //process remaining windows
         for(long long int i=k;i<N;i++){
             //ans of old window
             if(que.empty()){
                 ans.push_back(0);
             }
             else{
                ans.push_back(A[que.front()]);
             }
             
             //out of window element ko remove kardo
            //  if(i<N && A[i]<0) {
            //      que.push(i);
            //  }
            //  if(A[i-k]<0 && que.front()==(i-k)){
            //      que.pop();
            //  }
             
             //Love Babber Solution
             while(!que.empty() && ((i-que.front())>=k)){
                 que.pop();
             }
             if(A[i]<0){
                 que.push(i);
             }
             
         }
         
         //ans for last window as  per love solution
         if(que.empty()){
             ans.push_back(0);
         }
         else{
             ans.push_back(A[que.front()]);
         }
         return ans;
         
 }