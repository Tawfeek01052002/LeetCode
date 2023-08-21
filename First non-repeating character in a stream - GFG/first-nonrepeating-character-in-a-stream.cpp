//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    int arr[26]={0};
		    deque<char> dq;
		    string ans="";
		    for(int i=0;i<A.size();i++){
		        
		        int index=(int) (A[i]-'a');
		        arr[index]++;
		        dq.push_back(A[i]);
		        
		        while(!dq.empty() && arr[(int)dq.front()-'a']>1){
		            dq.pop_front();
		        }
		        
		        if(dq.empty()){
		            ans.push_back('#');
		        }
		        else{
		            ans.push_back(dq.front());
		        }
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends