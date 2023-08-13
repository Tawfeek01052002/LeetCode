//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	//using recursion
	void reverseArray(vector<int>&a){
	    int i=0;
	    int j=a.size()-1;
	    while(i<j){
	        swap(a[i],a[j]);
	        i++;
	        j--;
	    }
	}
	vector<int> findSum(vector<int> &a, vector<int> &b) {
	    if(a.size()==0){
	        return b;
	    }
	    if(b.size()==0){
	        return a;
	    }
	    int i=a.size()-1;
	    int j=b.size()-1;
        vector<int> ans;
        int carry=0;
        int data1=0,data2=0;
        while(i>=0 || j>=0){
            if(i<0){
                data1=0;
            }
            else{
                data1=a[i];
            }
            if(j<0){
                data2=0;
            }
            else{
                data2=b[j];
            }
            int data=data1+data2+carry;
            carry=data/10;
            ans.push_back(data%10);
            i--;
            j--;
        }
        while(carry!=0){
            ans.push_back(carry%10);
            carry=carry/10;
        }
        reverseArray(ans);
        return ans;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        Solution ob;
        auto ans = ob.findSum(a, b);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends