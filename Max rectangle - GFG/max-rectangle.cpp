//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    //using stack
    // travelling left to check that curr histogram can store on left histogram
    vector<int> previousSmallerEle(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> ans(n, -1);
        stack<int> s;
        s.push(-1);
        for (int i = 0; i < n; i++)
        {
            while (s.top() != -1 && heights[s.top()] >= heights[i])
            {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    // travelling left to check that curr histogram can store on right histogram
    vector<int> nextSmallerEle(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> ans(n, -1);
        stack<int> s;
        s.push(-1);
        for (int i = n - 1; i >= 0; i--)
        {
            while (s.top() != -1 && heights[s.top()] >= heights[i])
            {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int> &heights)
    {
        vector<int> previous = previousSmallerEle(heights);
        vector<int> next = nextSmallerEle(heights);
        int maxArea = 0;
        int n = heights.size();
        for (int i = 0; i < n; i++)
        {
            if (next[i] == -1)
            {
                next[i] = n;
            }
            int l = heights[i];
            int b = next[i] - previous[i] - 1;
            int area = l * b;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
    int maxArea(int M[MAX][MAX], int n, int m) {
        
        //TLE solution 
        vector<int> arr(m,0);
        int maxArea=0;
        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                arr[i]=M[j][i]==1?arr[i]+1:0;
            }
            maxArea=max(maxArea,largestRectangleArea(arr));
        }
        return maxArea;
        
        //another solution using DP
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends