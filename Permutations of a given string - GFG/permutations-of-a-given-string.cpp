//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    set<string> ans;
	    
        void getPerm(string& s,int i,string str){
            
            if(i>=s.length()){
                ans.insert(str);
                return;
            }
            
            for(int j=i;j<s.length();j++){
                swap(s[i],s[j]);
                getPerm(s,i+1,str+s[i]);
                swap(s[i],s[j]);
            }
            
            
        }
	
		vector<string>find_permutation(string& S)
		{
		    // Code here there
		    getPerm(S,0,"");
		    
		    vector<string> result;
		    for(auto i : ans){
		        result.push_back(i);
		    }
		    sort(result.begin(),result.end());
		    return result;
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