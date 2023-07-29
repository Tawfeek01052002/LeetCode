//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void getPerm(string s,set<string>& ans,int i){
	        
	        if(i>=s.length()){
	           ans.insert(s);
	           return;
	        }
	        
	        for(int j=i;j<s.length();j++){
	            //swap
	            swap(s[i],s[j]);
	            
	            //recusive call
	            getPerm(s,ans,i+1);
	        }
	    }
		vector<string> find_permutation(string S)
		{
		    set<string> ans;
		    int i=0;
		    getPerm(S,ans,i);
		    
		    vector<string> out;
		    for(string ele:ans){
		        out.push_back(ele);
		    }
		    
		    sort(out.begin(),out.end());
		    return out;
		    
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends