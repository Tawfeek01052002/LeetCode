//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<long long, long long> getMinMax(long long a[], int n) ;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        pair<ll, ll> pp = getMinMax(a, n);

        cout << pp.first << " " << pp.second << endl;
    }
    return 0;
}
// } Driver Code Ends

long long getMax(long long a[],int n){
    if(n==1){
        return a[0];
    }
    return max(a[n-1],getMax(a,n-1));
}

long long getMin(long long a[],int n){
    if(n==1){
        return a[0];
    }
    return min(a[n-1],getMin(a,n-1));
}

pair<long long, long long> getMinMax(long long a[], int n) {
    return {getMin(a,n),getMax(a,n)};
}