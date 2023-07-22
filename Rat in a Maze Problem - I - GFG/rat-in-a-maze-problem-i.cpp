//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> ans;
    void getPaths(vector<vector<int>>& m,vector<vector<bool>>& mark,int i,int j,int n,string& str){
        //Base Condition
        if(i<0 || j<0 || i>=n || j>=n || m[i][j]!=1 || mark[i][j]){
            return;
        }
        mark[i][j]=true;
        
        if(i==n-1 && j==n-1){
            ans.push_back(str);
            mark[i][j]=false;
            return;
        }
        
        //Down
        str.push_back('D');
        getPaths(m,mark,i+1,j,n,str);
        str.pop_back();
        
        //left
        str.push_back('L');
        getPaths(m,mark,i,j-1,n,str);
        str.pop_back();
        
        //right
        str.push_back('R');
        getPaths(m,mark,i,j+1,n,str);
        str.pop_back();
        
        //up
        str.push_back('U');
        getPaths(m,mark,i-1,j,n,str);
        str.pop_back();
        
        mark[i][j]=false;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<bool>> mark(n, vector<bool>(n, false));
        mark[0][0]=false;
        string str;
        getPaths(m,mark,0,0,n,str);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends